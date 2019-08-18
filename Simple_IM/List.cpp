#include "List.h"
#include "MsgType.h"
#include "qjsondocument.h"
#include "Client.h"
#include "qvector.h"
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
	connect(Client::getInstance(), SIGNAL(ListRefreshed(QVector<QJsonObject>)), this, SLOT(onListRefreshed(QVector<QJsonObject>)));
}


List::~List()
{
}

/**
*Function: RefreshList
*Description: 向服务器发出刷新列表请求
*param:
*return:发送成功返回真
*/
bool List::RefreshList()
{
	QJsonObject msg_json;
	msg_json.insert("type", MsgType::getFriendList);

	QJsonDocument msg(msg_json);

	Client* myClient = Client::getInstance();

	//发出请求
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

/**
*Function: onListRefreshed
*Description: 服务器返回好友列表时调用,并将列表信息交给ListGUI显示
*param:
*	-userArray:好友列表
*/
void List::onListRefreshed(QVector<QJsonObject>userArray)
{
	emit ListRefreshed(userArray);
}