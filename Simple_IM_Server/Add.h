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

	/**
	*Function: AddContact
	*Description: �����ݿ�����Ӻ��ѹ�ϵ
	*param:
	*	-info:�ͻ��˷�����������Ϣ
	*	-client:���ӿͻ��˵��׽���
	*/
	bool AddContact(QJsonObject info,QTcpSocket* client);

private:
	static QMutex mutex;
	static Add* m_instance;
	RemoteDB* db;//���ݿ�ӿ�
	Add();
	~Add();
};

