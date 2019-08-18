#include "Simple_IM_Server.h"
#include "Server.h"
#include "qstring.h"
#include "qtcpsocket.h"
#include "qstandarditemmodel.h"
#include"qhostinfo.h"
Simple_IM_Server::Simple_IM_Server(QWidget *parent)
	: QMainWindow(parent)
{
	
	ui.setupUi(this);
	connect(Server::getInstance(), SIGNAL(newClientSignIn(int, QString, QTcpSocket*)), this, SLOT(onNewClientSignIn(int, QString, QTcpSocket*)));
	connect(Server::getInstance(), SIGNAL(ClientLogOut(int, QString, QTcpSocket*)), this, SLOT(onClientLogOut(int, QString, QTcpSocket*)));

}

/**
*Function: onNewClientSignIn
*Description: 新用户登录后显示用户的id，ip等信息
*param:
*	-user_id:用户id
*	-username:用户名
*	-socket:与用户客户端连接的套接字
*/
void Simple_IM_Server::onNewClientSignIn(int user_id, QString username, QTcpSocket* socket)
{
	//获取列表行数，在末尾追加一行
	int row = ui.tableWidget->rowCount();
	ui.tableWidget->insertRow(row);

	//在最后一行填入信息
	ui.tableWidget->setItem(row, 0, new QTableWidgetItem(QString("%1").arg(user_id)));
	ui.tableWidget->setItem(row, 1, new QTableWidgetItem(username));
	ui.tableWidget->setItem(row, 2, new QTableWidgetItem(socket->peerAddress().toString()));
	ui.tableWidget->setItem(row, 3, new QTableWidgetItem(QString("%1").arg(socket->peerPort())));

}

/**
*Function: onClientLogOut
*Description: 用户登出后在显示的列表中删除该用户
*param:
*	-user_id:用户id
*	-username:用户名
*	-socket:与用户客户端连接的套接字
*/
void Simple_IM_Server::onClientLogOut(int user_id, QString username, QTcpSocket * socket)
{
	int row = 0;

	//找到登出用户在第几行
	for (row = 0; row < ui.tableWidget->rowCount(); row++)
	{
		qDebug() << ui.tableWidget->item(row, 0)->data(Qt::DisplayRole).toInt();
		if (ui.tableWidget->item(row, 0)->data(Qt::DisplayRole).toInt() == user_id)
			break;
	}

	//删除该条记录
	ui.tableWidget->removeRow(row);
}
