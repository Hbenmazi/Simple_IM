#pragma once
#include<QtSql>
#include<QMutex>
/**
 * @brief Զ�����ݿ�
 * ������ ʹ�õ���ģʽ��������ͨ������������ݿ�
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