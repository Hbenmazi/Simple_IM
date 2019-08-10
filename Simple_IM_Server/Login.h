#pragma once

#include<QMutex>
#include<QString>
#include<RemoteDB.h>
#include"qtcpsocket.h"
#include"qtcpsocket.h"
/**
 * @brief 服务器端完成登录功能的类
 * 描述： 使用单例模式
 */
class Login:public QObject
{
	Q_OBJECT
public:

	static Login* getInstance();
	bool SignIn(QJsonObject userinfo,QTcpSocket* client) ;

private:
	static QMutex mutex;
	static Login* m_instance;
	RemoteDB* db;

	Login();
	~Login();
};

