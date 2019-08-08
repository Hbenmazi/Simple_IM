#include "Register.h"


Register* Register::m_instance = NULL;
QMutex  Register::mutex;

Register* Register::getInstance()//GOF-Singleton
{

	if (!m_instance)
	{
		QMutexLocker locker(&mutex);
		if (!m_instance)
		{
			m_instance = new Register;
		}

	}
	return m_instance;
}


bool Register::SignUp(QString username, QString password,QString nicakname,QString email) const
{
	QSqlQuery query(db->getDB());

	//�жϲ�ѯ�Ƿ�ɹ�
	if (query.exec("select * from user where username = \" " +username+ " \" ") == false)
	{
		qDebug() << "\n\n" << query.lastError().text().toUtf8() << "\n\n";
		return 0;
	}
	else
	{
		//�ж��û����Ƿ����
		if (query.size() == 0)
		{
			query.finish();//�������һ�β�ѯ

			//�жϲ����Ƿ�ɹ�
			if (query.exec("insert user values( nul,\" " + username + "\""+"," + "\"" + password +"\""+ "," + "\"" + nicakname + "\""+"," + "\"" +email + "\""+")"))
			{
				qDebug() << "sign up successfully";
				return 1;
			}
			else
			{
				qDebug() << "\n\n" << query.lastError().text() << "\n\n";
				return 0;
			}

		}
		else
		{
			qDebug() << "\n\n" << "username has been signed up"<< "\n\n";
			return 0;
		}
	}
}