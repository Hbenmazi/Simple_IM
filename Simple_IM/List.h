#pragma once
#include <qobject.h>
#include "qvector.h"
#include "qjsonobject.h"
#include <QMutex>
#include "qstring.h"
class List :
	public QObject
{
	Q_OBJECT
public:
	static List* getInstance();
	
public slots:
	void onListRefreshed(QVector<QJsonObject> userArray);
	bool RefreshList();
	void setUsername(QString username);
	

private:
	static QMutex mutex;
	static List* m_instance;
	QString username;

	List();
	~List();
	


signals:
	void ListRefreshed(QVector<QJsonObject> userArray);
};
