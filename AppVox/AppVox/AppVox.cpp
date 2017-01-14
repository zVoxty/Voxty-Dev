#include "AppVox.h"

AppVox::AppVox(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.exit, SIGNAL(clicked()), this, SLOT(Submit()));
	connect(ui.connectToServer, SIGNAL(clicked()), this, SLOT(ConnectBtn()));
	connect(ui.disconnectToServer, SIGNAL(clicked()), this, SLOT(DisconnectBtn()));
	connect(ui.chatButton, SIGNAL(clicked()), this, SLOT(EnableChat()));

	QFile file("css.txt");
	file.open(QIODevice::ReadOnly);
	QTextStream instream(&file);
	QString line = instream.readLine();
	file.close();

	setStyleSheet(line);

	isConnected = false;
}

AppVox::~AppVox()
{

}
