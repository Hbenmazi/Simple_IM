#pragma once
#include<QtSql>
#include<QMutex>

class RemoteDB
{

public:
	static RemoteDB* getInstance();
	QSqlDatabase getDB() const;

	
private:
	static RemoteDB * m_instance;
	static QMutex mutex;
	QSqlDatabase db;

	RemoteDB()
	{
	    db = QSqlDatabase::addDatabase("QMYSQL");
		db.setHostName("cdb-0rl5a0gc.bj.tencentcdb.com");
		db.setPort(10156);
		db.setDatabaseName("Simple_IM_DB");
		db.setUserName("root");
		db.setPassword("Hezhiwei0616$");
		bool ok = db.open();

		if (!ok)
			qDebug() << "数据库打开失败";
	};
};


