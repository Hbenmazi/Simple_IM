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

	/**
	*Function: SignIn
	*Description: 处理登录请求
	*param:
	*	-userinfo:客户端用户名
	*	-client:连接客户端的套接字
	*/
	bool SignIn(QJsonObject userinfo,QTcpSocket* client) ;

private:
	static QMutex mutex;
	static Login* m_instance;
	RemoteDB* db;//数据库接口

	Login();
	~Login();
};

