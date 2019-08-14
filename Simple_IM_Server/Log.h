#pragma once
#include"qobject.h"
#include<QMutex>
#include<QString>
#include<RemoteDB.h>
#include"qtcpsocket.h"
#include"qtcpsocket.h"
#include"qjsonobject.h"

/**
 * @brief �������˴��������¼����
 * ������ ʹ�õ���ģʽ
 */
class Log :public QObject
{
	Q_OBJECT

public:
	static Log* getInstance();
	void ReturnLog(QJsonObject data, QTcpSocket* client);
	void SendNewMsg(QJsonObject data, QTcpSocket* client);


private:
	static QMutex mutex;
	static Log* m_instance;
	RemoteDB* db;

	Log();
	~Log();
};
