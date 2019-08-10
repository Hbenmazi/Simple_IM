#include "Simple_IM_Server.h"
#include "Server.h"
#include "qstring.h"
#include "qtcpsocket.h"
#include "qstandarditemmodel.h"
Simple_IM_Server::Simple_IM_Server(QWidget *parent)
	: QMainWindow(parent)
{
	
	ui.setupUi(this);
	connect(Server::getInstance(), SIGNAL(newClientSignIn(int, QString, QTcpSocket*)), this, SLOT(onNewClientSignIn(int, QString, QTcpSocket*)));
	connect(Server::getInstance(), SIGNAL(ClientLogOut(int, QString, QTcpSocket*)), this, SLOT(onClientLogOut(int, QString, QTcpSocket*)));
}

void Simple_IM_Server::onNewClientSignIn(int user_id, QString username, QTcpSocket* socket)
{
	
	QStringList value;

	int row = ui.tableWidget->rowCount();
	ui.tableWidget->insertRow(row);

	ui.tableWidget->setItem(row, 0, new QTableWidgetItem(QString("%1").arg(user_id)));
	ui.tableWidget->setItem(row, 1, new QTableWidgetItem(username));
	ui.tableWidget->setItem(row, 2, new QTableWidgetItem(socket->peerAddress().toString()));
	ui.tableWidget->setItem(row, 3, new QTableWidgetItem(QString("%1").arg(socket->peerPort())));

}

void Simple_IM_Server::onClientLogOut(int user_id, QString username, QTcpSocket * socket)
{
	int row = 0;
	for (row = 0; row < ui.tableWidget->rowCount(); row++)
	{
		qDebug() << ui.tableWidget->item(row, 0)->data(Qt::DisplayRole).toInt();
		if (ui.tableWidget->item(row, 0)->data(Qt::DisplayRole).toInt() == user_id)
			break;
	}
	ui.tableWidget->removeRow(row);
}
