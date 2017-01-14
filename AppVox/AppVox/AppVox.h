#ifndef APPVOX_H
#define APPVOX_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib") //Required for WinSock
#include <QtWidgets/QMainWindow>
#include <string>
#include <WinSock2.h>
#include <Windows.h>
#include <qfile.h>
#include <qtextstream.h>
#include "Chat.h"
//Other
#include "ui_Chat.h"
#include "ui_AppVox.h"
#include "PacketType.h"

class AppVox : public QMainWindow
{
	Q_OBJECT
	friend Chat;
public: //Public functions
	AppVox(QWidget *parent = 0);
	~AppVox();

	bool ConnectToServer(std::string IP, int PORT);

	bool SendPacketType(PacketType _packettype);

private: // Private functions

	static void ClientThread(); // This function handle packets from server

	bool ProcessPacket(PacketType _packettype);

	bool CloseConnection();

	//Get Functions
	bool GetInt32_t(int32_t & _int32_t);
	bool recvall(char * data, int totalbytes);
	bool GetPacketType(PacketType & _packettype);
	bool GetString(std::string & _string);

	//Sending Funcs
	bool sendall(char * data, int totalbytes);
	bool SendInt32_t(int32_t _int32_t);

private: //Private variables
	Ui::AppVoxClass ui;

	Chat *newChat = new Chat;

	SOCKET Connection;
	SOCKADDR_IN addr;
	int sizeOfAddr = sizeof(addr);

	std::string applicationName = "";
	std::string serverCurrentVersion = "";

	bool isConnected;
private slots:
	void exit();
	void ConnectBtn();
	void DisconnectBtn();
	void EnableChat();
};

static AppVox * clientptr;  //This client ptr is necessary so that the ClientThread method can access the Client instance/methods. Since the ClientThread method is static, this is the simplest workaround I could think of since there will only be one instance of the client.

#endif // APPVOX_H
