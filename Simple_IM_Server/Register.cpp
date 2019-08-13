#include "Register.h"
#include "../Simple_IM/MsgType.h"
#include "Server.h"
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

bool Register::SignUp(QJsonObject userinfo,QTcpSocket* client) const
{
	//��ȡ�û���Ϣ
	QString username = userinfo.value("username").toString();
	QString password = userinfo.value("password").toString();
	QString nickname = userinfo.value("nickname").toString();
	QString email = userinfo.value("email").toString();

	//��ʼ����ѯ���
	QSqlQuery query(db->getDB());

	//�Ȳ�ѯ�û����Ƿ��Ѿ���ע��
	if (query.exec("select * from user where username = \"" +username+ "\"") == false)//��ѯʧ��
	{
		//��ӡ������Ϣ
		qDebug() << "Server Error(signup,select):";
		qDebug() << "\n\n" << query.lastError().text().toUtf8() << "\n\n";
		return 0;
	}
	
	//�ж��û����Ƿ����
	if (query.size() == 0)
	{
		query.finish();//�������һ�β�ѯ

		//����user��,��ͻ��˷���ע��ɹ���Ϣ
		if (query.exec("insert user values( null,\"" + username + "\""+"," + "\"" + password +"\""+ "," + "\"" + nickname + "\""+"," + "\"" +email + "\""+")"))
		{
			qDebug() << "Server:";
			qDebug() << "sign up successfully";


			QJsonObject msg_json;
			msg_json.insert("type", MsgType::signupSuccess);
			msg_json.insert("username", username);

			QJsonDocument msg(msg_json);

			Server::getInstance()->SendMessageToClient(msg, client);
			return 1;
		}
		else
		{
			//����ʧ�ܣ����ش�����Ϣ
			qDebug() << "Server Error(signup,update):";
			qDebug() << "\n\n" << query.lastError().text() << "\n\n";

			QJsonObject msg_json;
			msg_json.insert("type", MsgType::signupFail);
			msg_json.insert("info", "Server error");

			QJsonDocument msg(msg_json);
			Server::getInstance()->SendMessageToClient(msg, client);
			return 0;
		}

	}
	else
	{
		//�û����Ѿ���ע��
		qDebug() << "Server:";
		qDebug() << "\n\n" << "username has been signed up"<< "\n\n";

		QJsonObject msg_json;
		msg_json.insert("type", MsgType::signupFail);
		msg_json.insert("info", "username has been signed up");

		QJsonDocument msg(msg_json);
		Server::getInstance()->SendMessageToClient(msg, client);
		return 0;
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

Register::~Register()
{

};