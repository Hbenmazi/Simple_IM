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
class Login:public QObject
{
	Q_OBJECT
public:

	static Login* getInstance();

	/**
	*Function: SignIn
	*Description: �����¼����
	*param:
	*	-userinfo:�ͻ����û���
	*	-client:���ӿͻ��˵��׽���
	*/
	bool SignIn(QJsonObject userinfo,QTcpSocket* client) ;

private:
	static QMutex mutex;
	static Login* m_instance;
	RemoteDB* db;//���ݿ�ӿ�

	Login();
	~Login();
};

