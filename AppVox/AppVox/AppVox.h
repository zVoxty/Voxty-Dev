#ifndef APPVOX_H
#define APPVOX_H

#include "Essentials.h"

class Chat;

class AppVox : public QMainWindow, public Essentials
{
	Q_OBJECT
public: //Public functions
	AppVox(QWidget *parent = 0);
	~AppVox();

	Chat* chatDialog;

public: //Private variables
	Ui::AppVoxClass ui;

private slots:
	void exit();
	void ConnectBtn();
	void DisconnectBtn();
	void EnableChat();
};

#endif // APPVOX_H
