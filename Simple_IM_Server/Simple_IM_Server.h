#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Simple_IM_Server.h"
#include "qstring.h"
#include "qtcpsocket.h"
class Simple_IM_Server : public QMainWindow
{
	Q_OBJECT

public:
	Simple_IM_Server(QWidget *parent = Q_NULLPTR);

public slots:
	void onNewClientSignIn(int user_id, QString username, QTcpSocket* socket);
	void onClientLogOut(int user_id, QString username, QTcpSocket* socket);

private:
	Ui::Simple_IM_ServerClass ui;
};
