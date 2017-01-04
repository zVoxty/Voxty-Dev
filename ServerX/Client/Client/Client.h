#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib,"ws2_32.lib") //Required for WinSock
#include <WinSock2.h> //For win sockets
#include <string> //For std::string
#include <iostream> //For std::cout, std::endl, std::cin.getline
#include "FileTransferData.h"
#include "PacketType.h"
#include <stdio.h>

class Client
{
public: //Public functions
	Client(std::string IP, int PORT);

	bool Connect();
	void RetryConnection();
	bool SendString(std::string & _string, bool IncludePacketType = true);
	bool SetUsername(std::string & _string);
	bool CloseConnection();
	bool RequestFile(std::string FileName);
	bool CheckClientVersion(std::string & _clientVersion);
	void UpdateClient();

public:
	bool sessionActive;
	bool canSendMessages;
	std::string userName;
	bool needClientUpdate;
	std::string clientVersion;
	std::string serverVersion;

private: //Private functions
	bool ProcessPacket(PacketType _packettype);
	static void ClientThread();

	//Sending Funcs
	bool sendall(char * data, int totalbytes);
	bool SendInt32_t(int32_t _int32_t);
	bool SendPacketType(PacketType _packettype);


	//Getting Funcs
	bool recvall(char * data, int totalbytes);
	bool GetInt32_t(int32_t & _int32_t);
	bool GetPacketType(PacketType & _packettype);
	bool GetString(std::string & _string);

private:
	FileTransferData file; //Object that contains informations about our file

	SOCKET Connection;//This client's connection to the server
	SOCKADDR_IN addr; //Address to be binded to our Connection socket
	int sizeofaddr = sizeof(addr); //Need sizeofaddr for the connect function
};

static Client * clientptr; //This client ptr is necessary so that the ClientThread method can access the Client instance/methods. Since the ClientThread method is static, this is the simplest workaround I could think of since there will only be one instance of the client.