#include "Log.h"
#include "Server.h"
#include "../Simple_IM/MsgType.h"


QMutex Log::mutex;
Log*  Log::m_instance = NULL;

/**
*Function: ReturnLog
*Description: 向客户端返回聊天记录
*param:
*	-data:客户端信息
*	-client:连接客户端的套接字
*/
void Log::ReturnLog(QJsonObject data, QTcpSocket * client)
{
	QString user_id;
	QString peerUser_id;
	//提取用户信息
	QString username = data.value("username").toString();
	QString peerUsername = data.value("peerUsername").toString();

	//初始化查询语句
	QSqlQuery query(db->getDB());

	//获取双方的user_id
    query.exec("select * from user where username =  \"" + username +"\"");
	query.first();
	user_id = query.value("user_id").toString();
	query.finish();

	query.exec("select user_id from user where username =  \"" + peerUsername + "\"");
	query.first();
	peerUser_id = query.value("user_id").toString();
	query.finish();

	//查询聊天记录
	QString sql = QString("select * from log where(sender_id = %1 AND recv_id = %2) or (sender_id = %3 AND recv_id = %4) ORDER BY time").arg(user_id).arg(peerUser_id).arg(peerUser_id).arg(user_id);
	query.exec(sql);
	int size = query.size();

	//对于每一条记录
	while (query.next())
	{
		//提取聊天记录信息
		QString sender_name = (user_id == query.value("sender_id").toString() ? username : peerUsername);
		QString recv_name = (user_id != query.value("sender_id").toString() ? username : peerUsername);
		QString content = query.value("content").toString();
		QString time = query.value("time").toString();

		//发送给客户端
		QJsonObject msg_json;
		msg_json.insert("type", MsgType::logResult);
		msg_json.insert("sender_name", sender_name);
		msg_json.insert("recv_name", recv_name);
		msg_json.insert("content", content);
		msg_json.insert("time", time);

		QJsonDocument msg(msg_json);

		Server::getInstance()->SendMessageToClient(msg, client);
	}
}

/**
*Function: SendNewMsg
*Description: 处理新发送的消息
*param:
*	-data:客户端信息
*	-client:连接客户端的套接字
*/
void Log::SendNewMsg(QJsonObject data, QTcpSocket * client)
{
	QString sender_id;
	QString recv_id;

	//提取消息信息
	QString sender_name = data.value("sender_name").toString();
	QString recv_name = data.value("recv_name").toString();
	QString content = data.value("content").toString();

	//初始化查询语句
	QSqlQuery query(db->getDB());

	//获取双方的user_id
	query.exec("select * from user where username =  \"" + sender_name + "\"");
	query.first();
	sender_id = query.value("user_id").toString();
	query.finish();

	query.exec("select user_id from user where username =  \"" + recv_name + "\"");
	query.first();
	recv_id = query.value("user_id").toString();
	query.finish();

	//插入数据库
	QString insert_sql = QString("INSERT INTO log (sender_id,recv_id,group_id,content)VALUES(%1,%2,-1,\"%3\")").arg(sender_id).arg(recv_id).arg(content);


	if (query.exec(insert_sql)) 
	{
		QJsonObject msg_json;
		msg_json.insert("type", MsgType::logResult);
		msg_json.insert("sender_name", sender_name);
		msg_json.insert("recv_name", recv_name);
		msg_json.insert("content", content);
		msg_json.insert("time", QDateTime::currentDateTime().toString());

		QJsonDocument msg(msg_json);

		//将消息返回给发送方
		Server::getInstance()->SendMessageToClient(msg, client);

		//将消息返回给接收方
		for (User* user : *Server::getInstance()->getAllClients())
		{
			if (user->getUsername() == recv_name)
			{
				Server::getInstance()->SendMessageToClient(msg, user->getSocket());
				break;
			}
		}
	}
	else
	{
		qDebug() << "Server SendNewMsg:";
		qDebug() << "SQL ERROE:" << query.lastError();
	}
}

Log::Log()
{
	db = RemoteDB::getInstance();
}


Log::~Log()
{
}


Log* Log::getInstance()//GOF-Singleton
{

	if (!m_instance)
	{
		QMutexLocker locker(&mutex);
		if (!m_instance)
		{
			m_instance = new Log;
		}

	}
	return m_instance;
}
