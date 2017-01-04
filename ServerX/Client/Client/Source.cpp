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
	SetConsoleColors(0x0031 | 0x07 | FOREGROUND_INTENSITY);

	try {
		cout << "\n\t\t Connecting to server . . . \n";
		Client myClient("86.127.10.163", 1111);

		myClient.Connect(); // Try to connect the client
		myClient.Lobby();

	}
	catch (const char * msg) {
		MessageBoxA(NULL, msg, "Error", MB_OK | MB_ICONERROR);
	}
}

