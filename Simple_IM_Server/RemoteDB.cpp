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

/**
*Function: RemoteDB
*Description: ���캯������ʼ��db��Ա������Զ�����ݿ⽨������
*/
RemoteDB::RemoteDB()
{
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("cdb-0rl5a0gc.bj.tencentcdb.com");
	db.setPort(10156);
	db.setDatabaseName("Simple_IM_DB");
	db.setUserName("root");
	db.setPassword("Hezhiwei0616$");
	bool ok = db.open();

	if (!ok)
		qDebug() << "���ݿ��ʧ��";
};

