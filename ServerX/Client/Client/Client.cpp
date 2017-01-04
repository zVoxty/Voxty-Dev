#include "Client.h"

Client::Client(std::string IP, int PORT)
{
	//Winsock Startup
	WSAData wsaData;

	WORD DllVersion = MAKEWORD(2, 1);

	if (WSAStartup(DllVersion, &wsaData) != 0)
	{
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(0);
	}

	addr.sin_addr.s_addr = inet_addr(IP.c_str()); //Address 127.0.0.1 = localhost (This pc)

	addr.sin_port = htons(PORT); //Port to connect on

	addr.sin_family = AF_INET; //IPv4 Socket

	clientptr = this; //Update ptr to the client which will be used by our client thread
	userName = "Guest";
	canSendMessages = true;
	clientVersion = "1.0";
}

bool Client::ProcessPacket(PacketType _packettype)
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
	case PacketType::FileTransferByteBuffer: {
		int32_t buffersize;

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
	case PacketType::FileTransfer_EndOfFile: {
		
		std::cout << "File transfer completed. File received \n";
		std::cout << "File Name: " << file.fileName << std::endl;
		std::cout << "File Size(bytes) : " << file.bytesWritten << std::endl;

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
		userName = "Guest";
		break;
	}

	case PacketType::ServerVersionNOk: {
		MessageBoxA(NULL, "Old client version ! Updating client !", "Info", MB_OK | MB_ICONEXCLAMATION);
		UpdateClient();
		break;
	}
	case PacketType::ServerVersion: {

		if (!GetString(serverVersion)) //Get the chat message and store it in variable: Message
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

bool Client::UpdateClient() {
	if (serverVersion != clientVersion) {
		std::string file = "Client" + serverVersion + ".exe";
		remove(file.c_str());
		if (!RequestFile(file))
			return false;

		return true;
	}
	return false;
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

bool Client::Connect()
{
	Connection = socket(AF_INET, SOCK_STREAM, NULL); //Set Connection socket
	
	if (connect(Connection, (SOCKADDR*)&addr, sizeofaddr) != 0) //If we are unable to connect...
	{
		MessageBoxA(NULL, "Failed to Connect", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	if (!SendPacketType(PacketType::ServerVersion)) {
		MessageBoxA(NULL, "Cannot get server version !", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	system("CLS");
	std::cout << "\n\t\tConnected succesfully!" << std::endl;
	sessionActive = true;
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientThread, NULL, NULL, NULL); //Create the client thread that will receive any data that the server sends.

	return true;
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
