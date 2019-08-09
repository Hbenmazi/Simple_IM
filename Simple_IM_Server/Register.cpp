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

/**
*Function: SignUp
*Description: д���ݿ������ע�Ṧ��
*param:�û���Ϣ
*return;ע��ɹ�������
*tableAccess;user
*tableUpdate:user
*/
bool Register::SignUp(QString username, QString password,QString nickname,QString email) const
{
	//��ʼ����ѯ���
	QSqlQuery query(db->getDB());

	//�Ȳ�ѯ�û����Ƿ��Ѿ���ע��
	if (query.exec("select * from user where username = \" " +username+ " \" ") == false)//��ѯʧ��
	{
		//��ӡ������Ϣ
		qDebug() << "\n\n" << query.lastError().text().toUtf8() << "\n\n";
		return 0;
	}
	else
	{
		//�ж��û����Ƿ����
		if (query.size() == 0)
		{
			query.finish();//�������һ�β�ѯ

			//����user��
			if (query.exec("insert user values( nul,\" " + username + "\""+"," + "\"" + password +"\""+ "," + "\"" + nickname + "\""+"," + "\"" +email + "\""+")"))
			{
				qDebug() << "sign up successfully";
				return 1;
			}
			else
			{
				//����ʧ�ܣ����ش�����Ϣ
				qDebug() << "\n\n" << query.lastError().text() << "\n\n";
				return 0;
			}

		}
		else
		{
			//�û����Ѿ���ע��
			qDebug() << "\n\n" << "username has been signed up"<< "\n\n";
			return 0;
		}
	}
}

/**
*Function: Register
*Description: ���캯������ȡ���ݿ�����Գ�ʼ����Ա
*/
Register::Register()
{
	db = RemoteDB::getInstance();
};