#include "Simple_IM.h"
#include <QtWidgets/QApplication>
#include <QSqlDatabase>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Simple_IM w;

	w.show();
	return a.exec();
}
