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
	bool AddContact(QJsonObject info,QTcpSocket* client);

private:
	static QMutex mutex;
	static Add* m_instance;
	RemoteDB* db;
	Add();
	~Add();
};

