#pragma once
#include <qobject.h>

class Login :
	public QObject
{
public:
	Login();
	~Login();

	bool SignIn(QString username, QString password) const;
};

