#include "AppVox.h"

void AppVox::exit() {
	QApplication::exit();
}

void AppVox::ConnectBtn() {
	if (!ConnectToServer("86.126.33.49", 1111)) {
		MessageBoxA(NULL, "Error connection to server", "Error", MB_OK | MB_ICONERROR);
		return;
	}

	ui.connectToServer->setDisabled(true);
	ui.disconnectToServer->setDisabled(false);
	
}

void AppVox::DisconnectBtn()
{
	if (!CloseConnection()) {
		qDebug("Problem disconnection !");
		return;
	}
	ui.connectToServer->setDisabled(false);
	ui.disconnectToServer->setDisabled(true);
}

void AppVox::Submit() {
	QString x = ui.inputText->text();
	ui.inputText->setText("");
}

void AppVox::InputText() {

}

void AppVox::PrintText() {

}