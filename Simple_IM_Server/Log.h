#pragma once
#include"qobject.h"
#include<QMutex>
#include<QString>
#include<RemoteDB.h>
#include"qtcpsocket.h"
#include"qtcpsocket.h"
#include"qjsonobject.h"

/**
 * @brief 服务器端处理聊天记录的类
 * 描述： 使用单例模式
 */
class Log :public QObject
{
	Q_OBJECT

public:
	static Log* getInstance();

	/**
	*Function: ReturnLog
	*Description: 向客户端返回聊天记录
	*param:
	*	-data:客户端信息
	*	-client:连接客户端的套接字
	*/
	void ReturnLog(QJsonObject data, QTcpSocket* client);

	/**
	*Function: SendNewMsg
	*Description: 处理新发送的消息
	*param:
	*	-data:客户端信息
	*	-client:连接客户端的套接字
	*/
	void SendNewMsg(QJsonObject data, QTcpSocket* client);


private:
	static QMutex mutex;
	static Log* m_instance;
	RemoteDB* db;//数据库接口

	Log();
	~Log();
};
