#pragma once

#include<QMutex>
#include<QString>
#include<RemoteDB.h>
#include"qtcpsocket.h"
#include"qtcpsocket.h"
/**
 * @brief ����������ɺ����б��ܵ���
 * ������ ��ͻ��˷��غ����б�
 */
class List :public QObject
{
	Q_OBJECT
public:
	static List* getInstance();

	/**
	*Function: ReturnList
	*Description: ��ͻ��˷��غ����б�
	*param:
	*	-client:���ӿͻ��˵��׽���
	*/
	bool ReturnList(QTcpSocket* client);

private:
	static QMutex mutex;
	static List* m_instance;
	RemoteDB* db;//���ݿ�ӿ�

	List();
	~List();
};

