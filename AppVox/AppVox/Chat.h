#ifndef CHAT_H
#define CHAT_H

#include "ui_Chat.h"
#include <QTextTable>
#include <QScrollBar>
#include <QString>

class AppVox;

class Chat : public QDialog{
	Q_OBJECT
	friend AppVox;
public:
	Chat();
	~Chat();

public: // Private functions
	void AppendText(QString from, QString message);
private: // Private variables
	Ui::Chat myChat;

private slots:
	void Submit();
};

#endif // !CHAT_H
