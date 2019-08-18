#pragma once

#include<QMutex>
#include<QString>
#include<RemoteDB.h>
#include"qtcpsocket.h"
#include"qtcpsocket.h"
#include"qjsonobject.h"
/**
 * @brief 服务器端完成添加好友功能的类
 * 描述： 使用单例模式
 */
class Add :public QObject
{
	Q_OBJECT
public:

	static Add* getInstance();

	/**
	*Function: AddContact
	*Description: 在数据库中添加好友关系
	*param:
	*	-info:客户端发来的请求消息
	*	-client:连接客户端的套接字
	*/
	bool AddContact(QJsonObject info,QTcpSocket* client);

private:
	static QMutex mutex;
	static Add* m_instance;
	RemoteDB* db;//数据库接口
	Add();
	~Add();
};

