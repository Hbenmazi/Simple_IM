#include "Login.h"
#include "Server.h"
#include "../Simple_IM/MsgType.h"

QMutex Login::mutex;
Login*  Login::m_instance = NULL;

Login* Login::getInstance()//GOF-Singleton
{

	if (!m_instance)
	{
		QMutexLocker locker(&mutex);
		if (!m_instance)
		{
			m_instance = new Login;
		}

	}
	return m_instance;
}
/**
*Function: SignIn
*Description: д���ݿ������ע�Ṧ��
*param:�û���Ϣ
*return;ע��ɹ�������
*tableAccess;user
*tableUpdate:user
*/

bool Login::SignIn(QJsonObject userinfo,QTcpSocket* client)
{
	int user_id;//���ڱ����û�id

	//��ȡ�û���Ϣ
	QString username = userinfo.value("username").toString();
	QString password = userinfo.value("password").toString();

	//��ʼ����ѯ���
	QSqlQuery query(db->getDB());

	//�Ȳ�ѯ�û����Ƿ��Ѿ�ע��
	if (query.exec("select * from user where username = \"" + username + "\"") == false)//��ѯʧ��
	{
		//��ӡ������Ϣ
		qDebug() << "Server Error(signin,select):";
		qDebug() << "\n\n" << query.lastError().text().toUtf8() << "\n\n";
		return 0;
	}
	
	//�û���������
	if (query.size() == 0)
	{
		QJsonObject msg_json;
		msg_json.insert("type", MsgType::signinFail);
		msg_json.insert("info", "username has't been signed up");

		QJsonDocument msg(msg_json);

		Server::getInstance()->SendMessageToClient(msg, client);
		return 0;
	}

	//�û������ڣ���������
	query.first();//record��ͣ�ڵ�һ����¼֮ǰ��,ͨ��fisrt()ָ���һ����¼
	user_id = query.value("user_id").toInt();
	if (password.compare(query.value("passward").toString()) == 0)
	{
		qDebug() << query.value("passward").toString();
	    //�������
;		//�������ע��
		Server::getInstance()->RegisterClient(user_id,username,client);

		//��ͻ��˷��ص�½�ɹ���Ϣ
		QJsonObject msg_json;
		msg_json.insert("type", MsgType::signinSuccess);
		msg_json.insert("username", username);
		msg_json.insert("profile_index", query.value("profile_index").toString());

		QJsonDocument msg(msg_json);

		Server::getInstance()->SendMessageToClient(msg,client);
		return 1;
	}
	else
	{
		//���벻������ͻ��˷��ش�����Ϣ
		QJsonObject msg_json;
		msg_json.insert("type", MsgType::signinFail);
		msg_json.insert("info", "passward is wrong");

		QJsonDocument msg(msg_json);

		Server::getInstance()->SendMessageToClient(msg, client);
		return 0;
	}
	
}

Login::Login()
{
	db = RemoteDB::getInstance();
}


Login::~Login()
{
}
