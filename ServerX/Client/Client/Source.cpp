#include "Client.h"

using namespace std;

VOID WINAPI SetConsoleColors(WORD attribs) {
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFOEX cbi;
	cbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	GetConsoleScreenBufferInfoEx(hOutput, &cbi);
	cbi.wAttributes = attribs;
	SetConsoleScreenBufferInfoEx(hOutput, &cbi);
}

int main()
{
	SetConsoleTitle(TEXT("Lobby"));
	SetConsoleColors(0x0031 | 0x07 | FOREGROUND_INTENSITY);
	//allColours();
	cout << "\n\t\t Connecting to server . . . \n";
	Client myClient("86.127.10.163", 1111);

	if (!myClient.Connect()) {
		myClient.RetryConnection();
		main();
	}
	
	while (myClient.sessionActive) {
		if (!myClient.CheckClientVersion(myClient.clientVersion)) {
			MessageBoxA(NULL, "Cannot get server version !", "Error", MB_OK | MB_ICONEXCLAMATION);
		}

		system("CLS");
		cout << "Version " << myClient.clientVersion;
		cout << "\n\n\t\t Lobby\n\n";
		cout << "\t\t1)Join chat\n";
		cout << "\t\t2)Exit\n\n";
		cout << "\t\tYour option : ";

		int option;
		cin >> option;

		switch (option)
		{
		case 1: {
			system("CLS");
			cout << "\n\n\t\tWelcome to chat (type lobby to get back)!\n\n";
			string username;
			if (myClient.userName == "Guest") {
				cout << "\n\n\t\t Set your username :";
				
				cin >> username;
				
				if (!myClient.SetUsername(username)) {
					MessageBoxA(NULL, "Can't set this username", "Error", MB_OK | MB_ICONEXCLAMATION);
					break;
				}
			}

			myClient.userName = username;

			std::string userInput;
			while (myClient.canSendMessages) {
				getline(cin, userInput);
				if (userInput == "lobby")
					break;
				if(userInput != ""){
					if (!myClient.SendString(userInput))
						break;
				}
				Sleep(10);
			}

			break;
		}
		case 2:
			myClient.sessionActive = false;
			myClient.CloseConnection();
			break;
		default:
			MessageBoxA(NULL, "Invalid option !", "Error", MB_OK | MB_ICONINFORMATION);
			break;
		}
	}

	system("PAUSE");
}

