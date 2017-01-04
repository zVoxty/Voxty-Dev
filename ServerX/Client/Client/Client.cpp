#include "Client.h"

Client::Client(std::string IP, int PORT)
{
	//Winsock Startup
	WSAData wsaData;

	WORD DllVersion = MAKEWORD(2, 1);

	if (WSAStartup(DllVersion, &wsaData) != 0) 
	{
		throw("Winsock startup failed");
		exit(0);
	}

	addr.sin_addr.s_addr = inet_addr(IP.c_str()); //Address 127.0.0.1 = localhost (This pc)

	addr.sin_port = htons(PORT); //Port to connect on

	addr.sin_family = AF_INET; //IPv4 Socket

	clientptr = this; //Update ptr to the client which will be used by our client thread

	userName = ""; // Set username to null

	canSendMessages = true; // User can send messages

	clientVersion = "1.0.0.0"; // Current client version

	SetConsoleTitle(TEXT("xPress 1.0.0.0")); // Set console title

	getFile = false;
}

bool Client::ProcessPacket(PacketType _packettype) // Function used to process an received packet from server
{
	switch (_packettype)
	{

	case PacketType::ChatMessage: //If packet is a chat message packet
	{
		std::string Message; //string to store our message we received

		if (!GetString(Message)) //Get the chat message and store it in variable: Message
			return false; //If we do not properly get the chat message, return false

		std::cout << Message << std::endl; //Display the message to the user
		break;
	}

	case PacketType::FileTransferByteBuffer: { //If packet is an file transfer
		int32_t buffersize; // Declare buffersize

		if (!GetInt32_t(buffersize))
			return false;

		if (!recvall(file.buffer, buffersize))
			return false;

		file.outFileStream.write(file.buffer, buffersize);

		file.bytesWritten += buffersize;

		//std::cout << "Received byte buffer for file transfer of size " << buffersize << std::endl;

		SendPacketType(PacketType::FileTransferRequestNextBuffer);

		break;
	}

	case PacketType::FileTransfer_EndOfFile: { // This packet is received when and of file is reached 
		
		std::cout << "File transfer completed. File received \n";
		std::cout << "File Name: " << file.fileName << std::endl;
		std::cout << "File Size(bytes) : " << file.bytesWritten << std::endl;

		getFile = true;

		file.bytesWritten = 0;
		file.outFileStream.close();

		break;
	}

	case PacketType::CanSetUsername: {
		MessageBoxA(NULL, "Succesfull set username !", "Info", MB_OK | MB_ICONEXCLAMATION);
		break;
	}

	case PacketType::CantSetUsername: {
		MessageBoxA(NULL, "Username already exist !", "Info", MB_OK | MB_ICONEXCLAMATION);
		userName = "";
		break;
	}

	case PacketType::ServerCurrentVersion: {
		if (!GetString(serverVersion)) //Get the chat message and store it in variable: Message
			return false; //If we do not properly get the chat message, return false
		break;
	}

	case PacketType::ServerLastVersion: {
		if (!GetString(serverLastVersion)) //Get the chat message and store it in variable: Message
			return false; //If we do not properly get the chat message, return false
		break;
	}
	default: //If packet type is not accounted for
		std::cout << "Unrecognized packet: " << (int32_t)_packettype << std::endl; //Display that packet was not found
		break;
	}
	return true;
}  

bool Client::RequestFile(std::string FileName) {
	file.outFileStream.open(FileName, std::ios::binary);
	file.fileName = FileName;
	file.bytesWritten = 0;
	if (!file.outFileStream.is_open()) {
		std::cout << "ERROR : Function(Client::RequestFile) unable to open file : " << FileName << " for writing ! \n";
		return false;
	}

	std::cout << "\nRequesting file " << FileName << " : " << std::endl;

	if (!SendPacketType(PacketType::FileTransferRequestFile))
		return false;

	if (!SendString(FileName, false))
		return false;

	while (getFile == false) {
		Sleep(100);
	}

	return true;
}

bool Client::SetUsername(std::string & _string) {

	int32_t bufferlength = _string.size();

	if (!SendPacketType(PacketType::SetUsername))
		return false;

	if (!SendInt32_t(bufferlength))
		return false;

	if (!sendall((char*)_string.c_str(), bufferlength)) //Try to send string buffer... If buffer fails to send,
		return false; //Return false: Failed to send string buffer

	return true;
}

void Client::UpdateClient() {
	
	std::string file = "Client_" + serverVersion + ".exe";
	remove(file.c_str());
	RequestFile(file);
}

void Client::ClientThread()
{
	PacketType PacketType;

	while (true)
	{
		if (!clientptr->GetPacketType(PacketType)) //Get packet type
			break; //If there is an issue getting the packet type, exit this loop

		if (!clientptr->ProcessPacket(PacketType)) //Process packet (packet type)
			break; //If there is an issue processing the packet, exit this loop
	}

	system("CLS");
	std::cout << "\n\n\t\tLost connection to the server." << std::endl;

	if (clientptr->CloseConnection()) //Try to close socket connection..., If connection socket was closed properly
		std::cout << "\t\tSocket to the server was closed successfuly." << std::endl;
	else //If connection socket was not closed properly for some reason from our function
		std::cout << "\t\tSocket was not able to be closed." << std::endl;

}

void Client::VerifyVersions() {
	int x = 0;
	while (serverVersion == "" || serverLastVersion == "") {
		system("CLS");
		std::cout << "\nWaiting for server answer !\n";
		Sleep(50);
		x++;
		if (x == 200)
			throw("Server don't answer in expected time !");
	}

	if (serverVersion != clientVersion) {
		MessageBoxA(NULL, "Your client will be updated", "Error", MB_OK | MB_ICONINFORMATION);
		UpdateClient();	
		std::string file = "start Client_" + serverVersion + ".exe";
		system(file.c_str());
		getFile = false;
		MessageBoxA(NULL, "Client updated !", "Error", MB_OK | MB_ICONINFORMATION);
		exit(0);
	}
	else {
		std::string file = "Client_" + serverLastVersion + ".exe";
		remove(file.c_str());
	}
}

bool Client::Connect()
{
	Connection = socket(AF_INET, SOCK_STREAM, NULL); //Set Connection socket
	
	if (connect(Connection, (SOCKADDR*)&addr, sizeofaddr) != 0) //If we are unable to connect...
	{
		throw("Failed to Connect");
		return false;
	}

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientThread, NULL, NULL, NULL); //Create the client thread that will receive any data that the server sends.

	if (!SendPacketType(PacketType::ServerCurrentVersion)) {
		throw("Cannot get server version !");
		return false;
	}

	if (!SendPacketType(PacketType::ServerLastVersion)) {
		throw("Cannot get last server version !");
		return false;
	}

	VerifyVersions();

	system("CLS");
	std::cout << "\n\t\tConnected succesfully!" << std::endl;
	sessionActive = true;
	return true;
}

void Client::Lobby() {

	while (sessionActive) {
		system("CLS");
		std::cout << "\n\n\t\tWelcome to lobby !\n\n";
		std::cout << "\t1)Join Chat \n";
		std::cout << "\t2)Exit\n";
		std::cout << "  \tYourOption : ";
		int userOption;

		std::cin >> userOption;

		switch (userOption)
		{
		case 1: {
			system("CLS");
			std::cout << "\n\n\t\tWelcome to chat (type lobby to get back)!\n\n";

			std::string username;
			if (userName == "") {
				std::cout << "\n\n\t\t Set your username :";

				std::cin >> username;

				if (!SetUsername(username)) {
					MessageBoxA(NULL, "Can't set this username", "Error", MB_OK | MB_ICONEXCLAMATION);
					Lobby();
					break;
				}
			}

			userName = username;

			std::string userInput;
			while (canSendMessages) {
				std::getline(std::cin, userInput);
				if (userInput == "lobby")
					break;
				if (userInput != "") {
					if (!SendString(userInput))
						break;
				}
				Sleep(10);
			}

			break;
		}
		case 2:
			sessionActive = false;
			CloseConnection();
			break;
		default:
			MessageBoxA(NULL, "Invalid option !", "Error", MB_OK | MB_ICONINFORMATION);
			break;
		}
	}
}

void Client::RetryConnection() {
	for (int i = 5; i >= 1; --i) {
		system("CLS");
		std::cout << "\t\tFailed to connect to server retry in " << i << " seconds . . .";
		Sleep(1000);
	}
}

bool Client::CloseConnection()
{
	if (closesocket(Connection) == SOCKET_ERROR)
	{
		if (WSAGetLastError() == WSAENOTSOCK) //If socket error is that operation is not performed on a socket (This happens when the socket has already been closed)
			return true; //return true since connection has already been closed

		std::string ErrorMessage = "Failed to close the socket. Winsock Error: " + std::to_string(WSAGetLastError()) + ".";

		MessageBoxA(NULL, ErrorMessage.c_str(), "Error", MB_OK | MB_ICONERROR);

		return false;
	}
	return true;
}