#pragma once

#include<QMutex>
#include<QString>
#include<RemoteDB.h>
#include"qtcpsocket.h"
#include"qtcpsocket.h"
/**
 * @brief 服务器端完成好友列表功能的类
 * 描述： 向客户端返回好友列表
 */
class List :public QObject
{
	Q_OBJECT
public:
	static List* getInstance();

	/**
	*Function: ReturnList
	*Description: 向客户端返回好友列表
	*param:
	*	-client:连接客户端的套接字
	*/
	bool ReturnList(QTcpSocket* client);

private:
	static QMutex mutex;
	static List* m_instance;
	RemoteDB* db;//数据库接口

	List();
	~List();
};

