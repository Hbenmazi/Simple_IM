#pragma once

#include<QMutex>
#include<QString>
#include<RemoteDB.h>

class Register
{
public:
	static Register* getInstance();
	bool SignUp(QString username, QString password, QString nickname, QString email) const;
	bool SignIN(QString username, QString password) const;

private:
	static QMutex mutex;
	static Register* m_instance;
	RemoteDB* db;
	

	Register() 
	{
		db = RemoteDB::getInstance();
	};


};

