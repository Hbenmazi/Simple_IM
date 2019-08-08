#include "RemoteDB.h"

RemoteDB* RemoteDB::m_instance = NULL;
QMutex  RemoteDB::mutex;

RemoteDB* RemoteDB::getInstance()//GOF-Singleton
{


	if (!m_instance)
	{
		QMutexLocker locker(&mutex);
		if (!m_instance)
		{
			m_instance = new RemoteDB();
		}

	}
	return m_instance;
}
QSqlDatabase RemoteDB::getDB() const
{
	return db;
}


