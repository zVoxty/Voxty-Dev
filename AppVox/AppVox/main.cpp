#include "AppVox.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AppVox w;

	w.show();
	return a.exec();
}
