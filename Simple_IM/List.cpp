#include "List.h"
#include "MsgType.h"
#include "qjsondocument.h"
#include "Client.h"

QMutex List::mutex;
List*  List::m_instance = NULL;

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

List::List()
{
	connect(Client::getInstance(), SIGNAL(ListRefreshed(QJsonObject)), this, SLOT(onListRefreshed(QJsonObject)));
}


List::~List()
{
}

bool List::RefreshList()
{
	QJsonObject msg_json;
	msg_json.insert("type", MsgType::getFriendList);

	QJsonDocument msg(msg_json);

	Client* myClient = Client::getInstance();

	//·¢³öÇëÇó
	if (myClient->SendMessageToServer(msg))
	{
		qDebug() << "Client RefreshList:";
		qDebug() << "success to send RefreshList msg";
		return true;;
	}
	else
	{
		qDebug() << "Client RefreshList:";
		qDebug() << "fail to send RefreshList msg";
		return false;
	}
}

void List::setUsername(QString username)
{
	this->username = username;
}

void List::onListRefreshed(QJsonObject user)
{
	emit ListRefreshed(user);
}