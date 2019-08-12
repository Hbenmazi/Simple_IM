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
class List :public QObject
{
	Q_OBJECT
public:
	static List* getInstance();
	bool ReturnList(QJsonObject data, QTcpSocket* client);

private:
	static QMutex mutex;
	static List* m_instance;
	RemoteDB* db;

	List();
	~List();
};

