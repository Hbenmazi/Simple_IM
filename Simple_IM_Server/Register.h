#pragma once

#include<QMutex>
#include<QString>
#include<RemoteDB.h>
#include"qtcpsocket.h"
/**
 * @brief �����������ע�Ṧ�ܵ���
 * ������ ʹ�õ���ģʽ
 */

class Register
{
public:
	
	static Register* getInstance();

	/**
	*Function: SignUp
	*Description: д���ݿ������ע�Ṧ��
	*param:�û���Ϣ
	*return;ע��ɹ�������
	*tableAccess;user
	*tableUpdate:user
	*/
	bool SignUp(QJsonObject userinfo,QTcpSocket* client) const;

private:
	static QMutex mutex;
	static Register* m_instance;
	RemoteDB* db;//���ݿ�ӿ�
	
	Register();
	~Register();
	


};

