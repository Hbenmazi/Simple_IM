#include "Simple_IM_Server.h"
#include <QtWidgets/QApplication>
#include <QtSql>
#include <Register.h>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Simple_IM_Server w;
	w.show();
	Register* aa = Register::getInstance();
	aa->SignUp("hezhiwei3", "www111","abc","894286780@qq.com");

	return a.exec();
}
