#ifndef ESSENTIALS_H
#define ESSENTIALS_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib") //Required for WinSock
#include <QtWidgets/QMainWindow>
#include <string>
#include <WinSock2.h>
#include <Windows.h>
#include <QFile>
#include <qtextstream.h>
#include <QTextTable>
#include <QScrollBar>
#include <QString>

//Other
#include "ui_Chat.h"
#include "ui_AppVox.h"
#include "PacketType.h"

class AppVox;
class Essentials {
public:
	Essentials();
	~Essentials();

	static void ClientThread(); // This function handle packets from server

	bool ConnectToServer(std::string IP, int PORT);
	bool CloseConnection();

	bool ProcessPacket(PacketType _packettype);

	//Get Functions
	bool GetInt32_t(int32_t & _int32_t);
	bool recvall(char * data, int totalbytes);
	bool GetPacketType(PacketType & _packettype);
	bool GetString(std::string & _string);

	//Sending Funcs
	bool sendall(char * data, int totalbytes);
	bool SendInt32_t(int32_t _int32_t);
	bool SendPacketType(PacketType _packettype);

	SOCKET Connection;
	SOCKADDR_IN addr;
	int sizeOfAddr = sizeof(addr);

	AppVox * mainWindow;

	std::string applicationName = "";
	std::string serverCurrentVersion = "";

	bool isConnected;
};

static Essentials * clientptr;  //This client ptr is necessary so that the ClientThread method can access the Client instance/methods. Since the ClientThread method is static, this is the simplest workaround I could think of since there will only be one instance of the client.


#endif // !ESSENTIALS_H
