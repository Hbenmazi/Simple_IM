#include "Simple_IM.h"
#include <QtWidgets/QApplication>
#include <QSqlDatabase>
#include  "Simple_IM.h"
#include "ListGUI.h"
#include"FileTransfer.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	LoginGUI aa;
	aa.show();
	
	return a.exec();
}
