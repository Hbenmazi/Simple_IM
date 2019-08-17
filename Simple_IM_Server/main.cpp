#include "Simple_IM_Server.h"
#include <QtWidgets/QApplication>
#include <QtSql>
#include <Register.h>
#include "Server.h"
#include"qhostinfo.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	Simple_IM_Server w;
	w.show();
	
	Server* m_Server = Server::getInstance();
	m_Server->StartServer();

	return a.exec();
}
