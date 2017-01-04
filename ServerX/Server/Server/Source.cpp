#include "Server.h"

int main()
{
	bool serverCrash = false;

	Server MyServer(1111, true); //Create server on port 100

	for (int i = 0; i < 100; i++) //Up to 100 times...
	{
		MyServer.ListenForNewConnection(); //Accept new connection (if someones trying to connect)
	}

	serverCrash = true;

	if (serverCrash == true) {
		system("CLS");
		std::cout << "Crash! Server is restarting in 5 seconds ! " << std::endl;
		Sleep(5000);
		main();
	}
	system("pause");
	return 0;
}