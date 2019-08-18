#pragma once
#include<QtSql>
#include<QMutex>
/**
 * @brief 远程数据库
 * 描述： 使用单例模式，服务器通过该类访问数据库
 */
class RemoteDB
{

public:
	static RemoteDB* getInstance();
	QSqlDatabase getDB() const;

private:
	static RemoteDB * m_instance;
	static QMutex mutex;
	QSqlDatabase db;

	RemoteDB();

};