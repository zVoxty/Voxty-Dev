#ifndef CHAT_H
#define CHAT_H

#include "AppVox.h"

class Chat : public QDialog, public Essentials{
	Q_OBJECT
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
