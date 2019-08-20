#include "List.h"
#include "Server.h"
#include "../Simple_IM/MsgType.h"
QMutex List::mutex;
List*  List::m_instance = NULL;

/**
*Function: ReturnList
*Description: 向客户端返回好友列表
*param:
*	-client:连接客户端的套接字
*/
bool List::ReturnList(QTcpSocket * client)
{
	int user_id = 0;
	User* user;

	//通过套接字找到对应的User
	user = Server::getInstance()->SearchUserBySocket(client);

	if (!user)
	{
		qDebug() << "Server ReturnList:";
		qDebug() << "cant find the user";
		return false;
	}
	else
	{
		//设置user_id
		user_id = user->getUserId();

		//初始化查询语句
		QSqlQuery query(db->getDB());

		//向数据库查询好友信息
		QString sql;
		sql = QString("SELECT * FROM user WHERE user_id IN( SELECT recv_id from friendship WHERE sender_id = %1 UNION ALL SELECT sender_id from friendship WHERE recv_id = %2)").arg(user_id).arg(user_id);
		query.exec(sql);

		//对于每一个好友
		while (query.next())
		{
			//获取好友信息
			QString user_id = query.value(0).toString();
			QString username = query.value(1).toString();
			QString passward = query.value(2).toString();
			QString nickname = query.value(3).toString();
			QString email = query.value(4).toString();
			QString profile_index = query.value(5).toString();

			QJsonObject msg_json;
			msg_json.insert("type", MsgType::friendListResult);
			msg_json.insert("user_id", user_id);
			msg_json.insert("username", username);
			//msg_json.insert("passward", passward);
			msg_json.insert("nickname", nickname);
			msg_json.insert("email", email);
			msg_json.insert("profile_index", profile_index);

			QJsonDocument msg(msg_json);

			//发送给客户端
			Server::getInstance()->SendMessageToClient(msg, client);
			
		}

		return true;
	}
}

List::List()
{
	db = RemoteDB::getInstance();
}


List::~List()
{
}



List* List::getInstance()//GOF-Singleton
{

	if (!m_instance)
	{
		QMutexLocker locker(&mutex);
		if (!m_instance)
		{
			m_instance = new List;
		}

	}
	return m_instance;
}

