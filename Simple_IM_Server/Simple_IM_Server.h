#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Simple_IM_Server.h"
#include "qstring.h"
#include "qtcpsocket.h"

/**
 * @brief �������Ĵ���
 */
class Simple_IM_Server : public QMainWindow
{
	Q_OBJECT

public:
	Simple_IM_Server(QWidget *parent = Q_NULLPTR);

public slots:
	/**
	*Function: onNewClientSignIn
	*Description: ���û���¼����ʾ�û���id��ip����Ϣ
	*param:
	*	-user_id:�û�id
	*	-username:�û���
	*	-socket:���û��ͻ������ӵ��׽���
	*/
	void onNewClientSignIn(int user_id, QString username, QTcpSocket* socket);

	/**
	*Function: onClientLogOut
	*Description: �û��ǳ�������ʾ���б���ɾ�����û�
	*param:
	*	-user_id:�û�id
	*	-username:�û���
	*	-socket:���û��ͻ������ӵ��׽���
	*/
	void onClientLogOut(int user_id, QString username, QTcpSocket* socket);

private:
	Ui::Simple_IM_ServerClass ui;
};
