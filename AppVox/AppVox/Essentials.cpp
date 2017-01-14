#include "Essentials.h"
#include "AppVox.h"

Essentials::Essentials()
{
}

Essentials::~Essentials()
{
}

bool ConnectSock(SOCKET Connection, SOCKADDR_IN addr, int sizeOfAddr) {

	if (connect(Connection, (SOCKADDR*)&addr, sizeOfAddr) != 0) //If we are unable to connect...
		return false;
	return true;
}

bool Essentials::ConnectToServer(std::string IP, int PORT)
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
		qDebug("Problem Connection to server");
		return false;
	}

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientThread, NULL, NULL, NULL); //Create the client thread that will receive any data that the server sends.
	while (applicationName == "" || serverCurrentVersion == "") {
		Sleep(5);
	}

	isConnected = true;
	return true;
}

void Essentials::ClientThread()
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

bool Essentials::CloseConnection()
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
	isConnected = false;
	return true;
}