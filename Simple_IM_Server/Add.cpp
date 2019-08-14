#include "Add.h"
#include "Server.h"
#include "../Simple_IM/MsgType.h"
#include"User.h"
QMutex Add::mutex;
Add*  Add::m_instance = NULL;

Add* Add::getInstance()//GOF-Singleton
{

	if (!m_instance)
	{
		QMutexLocker locker(&mutex);
		if (!m_instance)
		{
			m_instance = new Add;
		}

	}
	return m_instance;
}


bool Add::AddContact(QJsonObject info,QTcpSocket* client)
{
	QJsonObject msg_json;

	//提取用户信息
	QString username = info.value("username").toString();
	QString targetUsername = info.value("targetUsername").toString();

	//初始化查询语句
	QSqlQuery query(db->getDB());

	//获取发出邀请一方的user_id
	query.exec("select user_id from user where username = \"" + username + "\"");
	query.next();//指向第一条记录
	QString sender_id = query.value(0).toString();
	query.finish();

	//获取接收方的user_id
	query.exec("select user_id from user where username = \"" + targetUsername + "\"");
	query.next();//指向第一条记录
	QString recv_id = query.value(0).toString();
	query.finish();

	//发送方与接收方相同
	if (sender_id == recv_id)
	{
		msg_json.insert("type", MsgType::addContactFail);
		msg_json.insert("info","can't add contact to yourself");

		QJsonDocument msg(msg_json);

		Server::getInstance()->SendMessageToClient(msg, client);
		return false;
	}

	//接收方不存在
	if (recv_id.isNull())
	{
		msg_json.insert("type", MsgType::addContactFail);
		msg_json.insert("info", targetUsername+" doesn't exist");

		QJsonDocument msg(msg_json);

		Server::getInstance()->SendMessageToClient(msg, client);
		return false;
	}
	
	//检查好友关系是否已经存在
	query.exec("select * from friendship where sender_id = \"" + sender_id + "\""+"and recv_id = \"" + recv_id + "\"");
	if (query.size())
	{
		query.finish();
		msg_json.insert("type", MsgType::addContactFail);
		msg_json.insert("info", "Friendship has already existed");

		QJsonDocument msg(msg_json);

		Server::getInstance()->SendMessageToClient(msg, client);
		return false;
	}
	query.finish();

	//接收方存在，插入数据库
	bool success = query.exec("insert friendship values (" + sender_id+ "," + recv_id +")");
	query.finish();

	if (success)//注册成功
	{
		msg_json.insert("type", MsgType::addContactSuccess);

		QJsonDocument msg(msg_json);

		Server::getInstance()->SendMessageToClient(msg, client);

		for (User* user : *(Server::getInstance()->getAllClients()))
		{
			if (user->getUserId() == recv_id.toInt())
			{
				QJsonObject empty;
				List::getInstance()->ReturnList(empty, user->getSocket());
			}
		}

		return true;
	}
	else
	{
		msg_json.insert("type", MsgType::addContactFail);
		msg_json.insert("info", "SQL error");

		QJsonDocument msg(msg_json);

		Server::getInstance()->SendMessageToClient(msg, client);
		return false;
	}
	


}

Add::Add()
{
	db = RemoteDB::getInstance();
	
}


Add::~Add()
{
}
