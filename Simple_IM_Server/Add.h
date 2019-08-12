#pragma once

#include<QMutex>
#include<QString>
#include<RemoteDB.h>
#include"qtcpsocket.h"
#include"qtcpsocket.h"
#include"qjsonobject.h"
/**
 * @brief �������������Ӻ��ѹ��ܵ���
 * ������ ʹ�õ���ģʽ
 */
class Add :public QObject
{
	Q_OBJECT
public:

	static Add* getInstance();
	bool AddContact(QJsonObject info,QTcpSocket* client);

private:
	static QMutex mutex;
	static Add* m_instance;
	RemoteDB* db;
	Add();
	~Add();
};

