#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Simple_IM_Server.h"
#include "qstring.h"
#include "qtcpsocket.h"

/**
 * @brief 服务器的窗口
 */
class Simple_IM_Server : public QMainWindow
{
	Q_OBJECT

public:
	Simple_IM_Server(QWidget *parent = Q_NULLPTR);

public slots:
	/**
	*Function: onNewClientSignIn
	*Description: 新用户登录后显示用户的id，ip等信息
	*param:
	*	-user_id:用户id
	*	-username:用户名
	*	-socket:与用户客户端连接的套接字
	*/
	void onNewClientSignIn(int user_id, QString username, QTcpSocket* socket);

	/**
	*Function: onClientLogOut
	*Description: 用户登出后在显示的列表中删除该用户
	*param:
	*	-user_id:用户id
	*	-username:用户名
	*	-socket:与用户客户端连接的套接字
	*/
	void onClientLogOut(int user_id, QString username, QTcpSocket* socket);

private:
	Ui::Simple_IM_ServerClass ui;
};
