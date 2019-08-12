#pragma once
#include "qstring.h"
#include <qobject.h>
#include "qjsonobject.h"

class Add:public QObject
{
	Q_OBJECT
public:
	Add();
	~Add();
	bool AddContact(QString username,QString targetUsername) const;

private:

signals:
	void AddContactSuccess(QJsonObject data);
	void AddContactFail(QJsonObject data);

};

