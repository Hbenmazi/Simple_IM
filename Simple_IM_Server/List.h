#pragma once

#include<QMutex>
#include<QString>
#include<RemoteDB.h>
#include"qtcpsocket.h"
#include"qtcpsocket.h"
/**
 * @brief ����������ɵ�¼���ܵ���
 * ������ ʹ�õ���ģʽ
 */
class List :public QObject
{
	Q_OBJECT
public:
	static List* getInstance();
	bool ReturnList(QJsonObject data, QTcpSocket* client);

private:
	static QMutex mutex;
	static List* m_instance;
	RemoteDB* db;

	List();
	~List();
};

