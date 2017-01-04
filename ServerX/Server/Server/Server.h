#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib") //Required for WinSock
#include <WinSock2.h> //For win sockets
#include <string> //For std::string
#include <iostream> //For std::cout, std::endl
#include "FileTransferData.h"
#include "PacketManager.h"
#include "PacketStructs.h"
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include <vector> //for std::vector

class Connection
{
public:
	Connection(SOCKET socket_)
	{
		socket = socket_;
		ActiveConnection = true; //Default to active connection 
	}

	bool ActiveConnection; //True if connection is active, false if inactive(due to a disconnect)

	SOCKET socket;
	//file transfer data
	FileTransferData file; //Object that contains information about our file that is being sent to the client from this server
	PacketManager pm; //Packet Manager for outgoing data for this connection

	std::string connectionName;
};

class Server
{
public:
	Server(int PORT, bool BroadcastPublically = false);
	bool ListenForNewConnection();
	

private:

	bool sendall(int ID, char * data, int totalbytes);
	bool recvall(int ID, char * data, int totalbytes);

	bool Getint32_t(int ID, int32_t & _int32_t);
	bool GetPacketType(int ID, PacketType & _packettype);

	void SendString(int ID, std::string & _string);
	void SendCustomString_Packet(int ID, std::string & _string, PacketType _packettype);
	bool GetString(int ID, std::string & _string);

	bool ProcessPacket(int ID, PacketType _packettype);
	bool HandleSendFile(int ID);

	static void ClientHandlerThread(int ID);
	static void PacketSenderThread();

	void DisconnectClient(int ID); //Called to properly disconnect and clean up a client (if possible)
private:
	std::vector<std::shared_ptr<Connection>> connections;
	std::mutex connectionMgr_mutex; //mutex for managing connections (used when a client disconnects)
	int UnusedConnections = 0; //# of Inactive Connection Objects that can be reused

	std::string serverVersion;
	std::string serverLastVersion;

	SOCKADDR_IN addr; //Address that we will bind our listening socket to
	int addrlen = sizeof(addr);
	SOCKET sListen;

private: //Variables and functions to check runtime
	std::clock_t c_start = std::clock();
	std::chrono::time_point<std::chrono::steady_clock> t_start;
	std::chrono::time_point<std::chrono::steady_clock> t_end;
	std::string stringify(double x)
	{
		std::ostringstream o;
		if (!(o << x))
		{
			return "INVALID CONVERSION";
		}
		return o.str();
	}

	void Start()
	{
		t_start = std::chrono::high_resolution_clock::now();
	}
	void Stop()
	{
		t_end = std::chrono::high_resolution_clock::now();
	}
	std::string GetMsElapsedAsString()
	{
		std::string timestring;
		double msElapsed = std::chrono::duration<double, std::milli>(t_end - t_start).count();
		timestring = stringify(msElapsed);
		return timestring;
	}
	double GetMsElapsedAsDouble()
	{
		double msElapsed = std::chrono::duration<double, std::milli>(t_end - t_start).count();
		return msElapsed;
	}
};

static Server * serverptr; //Serverptr is necessary so the static ClientHandler method can access the server instance/functions.
