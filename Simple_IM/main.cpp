#include "Simple_IM.h"
#include <QtWidgets/QApplication>
#include <QSqlDatabase>
#include  "Simple_IM.h"
#include "ListGUI.h"
#include"FileTransfer.h"
#include"Address.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Address* add = Address::getInstance();
	add->show();
	
	return a.exec();
}
