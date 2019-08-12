#pragma once
#include <qobject.h>
#include"qstring.h"

class Login :
	public QObject
{
	Q_OBJECT
public:
	Login();
	~Login();

	bool SignIn(QString username, QString password) const;

public slots:
	void onSignInSuccess(QString username);
	void onSignInFail(QString info);

signals:
	void SignInSuccess(QString username);
	void SignInFail(QString info);

};

