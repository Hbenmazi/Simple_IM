#pragma once

#include<QMutex>
#include<QString>
#include<RemoteDB.h>
#include"qtcpsocket.h"
/**
 * @brief ����������ɵ�¼���ܵ���
 * ������ ʹ�õ���ģʽ
 */
class Login
{
public:

	static Login* getInstance();
	bool SignIn(QJsonObject userinfo,QTcpSocket* client) const;

private:
	static QMutex mutex;
	static Login* m_instance;
	RemoteDB* db;

	Login();
	~Login();
};

