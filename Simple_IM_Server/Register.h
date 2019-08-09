#pragma once

#include<QMutex>
#include<QString>
#include<RemoteDB.h>
/**
 * @brief �����������ע�Ṧ�ܵ���
 * ������ ʹ�õ���ģʽ
 */

class Register
{
public:
	
	static Register* getInstance();
	bool SignUp(QJsonObject userinfo) const;

private:
	static QMutex mutex;
	static Register* m_instance;
	RemoteDB* db;
	
	Register();
	


};

