#include "Log.h"
#include "Server.h"
#include "../Simple_IM/MsgType.h"


QMutex Log::mutex;
Log*  Log::m_instance = NULL;

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

	QString sql = QString("select * from log where(sender_id = %1 AND recv_id = %2) or (sender_id = %3 AND recv_id = %4) ORDER BY time").arg(user_id).arg(peerUser_id).arg(peerUser_id).arg(user_id);
	

	query.exec(sql);
	int size = query.size();
	while (query.next())
	{
		QString sender_name = (user_id == query.value("sender_id").toString() ? username : peerUsername);
		QString recv_name = (user_id != query.value("sender_id").toString() ? username : peerUsername);

		QString content = query.value("content").toString();
		QString time = query.value("time").toString();

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
