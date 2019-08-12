#include "List.h"
#include "Server.h"
#include "../Simple_IM/MsgType.h"
QMutex List::mutex;
List*  List::m_instance = NULL;

bool List::ReturnList(QJsonObject data, QTcpSocket * client)
{
	int user_id = 0;
	User* user;
	user = Server::getInstance()->SearchUserBySocket(client);
	if (!user)
	{
		qDebug() << "Server ReturnList:";
		qDebug() << "cant find the user";
		return false;
	}
	else
	{
		user_id = user->getUserId();

		//³õÊ¼»¯²éÑ¯Óï¾ä
		QSqlQuery query(db->getDB());

		QString sql;
		sql = QString("SELECT * FROM user WHERE user_id IN( SELECT recv_id from friendship WHERE sender_id = %1 )").arg(user_id);
		query.exec(sql);
		while (query.next()) {
			QString user_id = query.value(0).toString();
			QString username = query.value(1).toString();
			QString passward = query.value(2).toString();
			QString nickname = query.value(3).toString();
			QString email = query.value(4).toString();

			QJsonObject msg_json;
			msg_json.insert("type", MsgType::friendListResult);
			msg_json.insert("user_id", user_id);
			msg_json.insert("username", username);
			msg_json.insert("passward", passward);
			msg_json.insert("nickname", nickname);
			msg_json.insert("email", email);

			QJsonDocument msg(msg_json);

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

