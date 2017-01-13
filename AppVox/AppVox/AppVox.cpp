#include "AppVox.h"

AppVox::AppVox(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.exit, SIGNAL(clicked()), this, SLOT(exit()));
	connect(ui.connectToServer, SIGNAL(clicked()), this, SLOT(ConnectBtn()));
	connect(ui.disconnectToServer, SIGNAL(clicked()), this, SLOT(DisconnectBtn()));
}

AppVox::~AppVox()
{

}

bool ConnectSock(SOCKET Connection, SOCKADDR_IN addr, int sizeOfAddr) {
	if (connect(Connection, (SOCKADDR*)&addr, sizeOfAddr) != 0) //If we are unable to connect...
		return false;
	return true;
}

bool AppVox::ConnectToServer(std::string IP, int PORT)
{
	//Winsock Startup
	WSAData wsaData;

	WORD DllVersion = MAKEWORD(2, 1);

	if (WSAStartup(DllVersion, &wsaData) != 0)
		qDebug("Winsock startup failed");

	addr.sin_addr.s_addr = inet_addr(IP.c_str()); //Address 127.0.0.1 = localhost (This pc)

	addr.sin_port = htons(PORT); //Port to connect on

	addr.sin_family = AF_INET; //IPv4 Socket

	clientptr = this; //Update ptr to the client which will be used by our client thread

	Connection = socket(AF_INET, SOCK_STREAM, NULL); //Set Connection socket

	if (!ConnectSock(Connection, addr, sizeOfAddr)) {
		qDebug("Problem Connection socket");
		return false;
	}

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientThread, NULL, NULL, NULL); //Create the client thread that will receive any data that the server sends.

	/*if (!SendPacketType(PacketType::ServerCurrentVersion)) {
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
	sessionActive = true;*/

	return true;
}

void AppVox::ClientThread()
{
	PacketType PacketType;

	while (true)
	{
		if (!clientptr->GetPacketType(PacketType)) //Get packet type
			break; //If there is an issue getting the packet type, exit this loop

		if (!clientptr->ProcessPacket(PacketType)) //Process packet (packet type)
			break; //If there is an issue processing the packet, exit this loop
	}

	qDebug("Lost connection to the server.");

	if (clientptr->CloseConnection()) //Try to close socket connection..., If connection socket was closed properly
		qDebug("Socket to the server was closed successfuly.");
	else //If connection socket was not closed properly for some reason from our function
		qDebug("Socket was not able to be closed.");
}

bool AppVox::ProcessPacket(PacketType _packettype)
{
	switch (_packettype)
	{

	//case PacketType::ChatMessage: //If packet is a chat message packet
	//{
	//	std::string Message; //string to store our message we received

	//	if (!GetString(Message)) //Get the chat message and store it in variable: Message
	//		return false; //If we do not properly get the chat message, return false

	//	std::cout << Message << std::endl; //Display the message to the user
	//	break;
	//}

	//case PacketType::FileTransferByteBuffer: { //If packet is an file transfer
	//	int32_t buffersize; // Declare buffersize

	//	if (!GetInt32_t(buffersize))
	//		return false;

	//	if (!recvall(file.buffer, buffersize))
	//		return false;

	//	file.outFileStream.write(file.buffer, buffersize);

	//	file.bytesWritten += buffersize;

	//	//std::cout << "Received byte buffer for file transfer of size " << buffersize << std::endl;

	//	SendPacketType(PacketType::FileTransferRequestNextBuffer);

	//	break;
	//}

	//case PacketType::FileTransfer_EndOfFile: { // This packet is received when and of file is reached 

	//	std::cout << "File transfer completed. File received \n";
	//	std::cout << "File Name: " << file.fileName << std::endl;
	//	std::cout << "File Size(bytes) : " << file.bytesWritten << std::endl;

	//	getFile = true;

	//	file.bytesWritten = 0;
	//	file.outFileStream.close();

	//	break;
	//}
	//case PacketType::SetUsername: {
	//	std::string handleUsername;
	//	if (!GetString(handleUsername))
	//		return false;



	//	if (handleUsername == "canSet") {
	//		std::cout << "\n\n\t\t\tSccesfull setting username !\n";
	//		canSendMessages = true;
	//	}

	//	if (handleUsername == "cantSet") {
	//		MessageBoxA(NULL, "Username already exist !", "Info", MB_OK | MB_ICONEXCLAMATION);
	//		canSendMessages = false;
	//	}

	//	break;
	//}

	//case PacketType::ServerCurrentVersion: {
	//	if (!GetString(serverVersion)) //Get the chat message and store it in variable: Message
	//		return false; //If we do not properly get the chat message, return false
	//	break;
	//}

	//case PacketType::ServerLastVersion: {
	//	if (!GetString(serverLastVersion)) //Get the chat message and store it in variable: Message
	//		return false; //If we do not properly get the chat message, return false
	//	break;
	//}

	//case PacketType::BanChat: {
	//	std::string message;
	//	if (!GetString(message))
	//		return false;

	//	message = "Banned from chat reason : " + message;
	//	MessageBoxA(NULL, message.c_str(), "ERROR", MB_OK | MB_ICONEXCLAMATION);
	//	canSendMessages = false;
	//	Lobby();
	//	break;
	//}

	default: //If packet type is not accounted for
		//std::cout << "Unrecognized packet: " << (int32_t)_packettype << std::endl; //Display that packet was not found
		qDebug("Unrecognized packet");
		break;
	}
	return true;
}

bool AppVox::CloseConnection()
{
	if (closesocket(Connection) == SOCKET_ERROR)
	{
		if (WSAGetLastError() == WSAENOTSOCK) //If socket error is that operation is not performed on a socket (This happens when the socket has already been closed)
			return true; //return true since connection has already been closed

		//std::string ErrorMessage = "Failed to close the socket. Winsock Error: " + std::to_string(WSAGetLastError()) + ".";
		//MessageBoxA(NULL, ErrorMessage.c_str(), "Error", MB_OK | MB_ICONERROR);
		qDebug("Failed to close the socket.");
		return false;
	}
	return true;
}
