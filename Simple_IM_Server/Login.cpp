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
*Description: 写数据库以完成注册功能
*param:用户信息
*return;注册成功返回真
*tableAccess;user
*tableUpdate:user
*/

bool Login::SignIn(QJsonObject userinfo,QTcpSocket* client)
{
	int user_id;//用于保存用户id

	//提取用户信息
	QString username = userinfo.value("username").toString();
	QString password = userinfo.value("password").toString();

	//初始化查询语句
	QSqlQuery query(db->getDB());

	//先查询用户名是否已经注册
	if (query.exec("select * from user where username = \"" + username + "\"") == false)//查询失败
	{
		//打印错误信息
		qDebug() << "Server Error(signin,select):";
		qDebug() << "\n\n" << query.lastError().text().toUtf8() << "\n\n";
		return 0;
	}
	
	//用户名不存在
	if (query.size() == 0)
	{
		QJsonObject msg_json;
		msg_json.insert("type", MsgType::signinFail);
		msg_json.insert("info", "username has't been signed up");

		QJsonDocument msg(msg_json);

		Server::getInstance()->SendMessageToClient(msg, client);
		return 0;
	}

	//用户名存在，检验密码
	query.first();//record是停在第一条记录之前的,通过fisrt()指向第一条记录
	user_id = query.value("user_id").toInt();
	if (password.compare(query.value("passward").toString()) == 0)
	{
		qDebug() << query.value("passward").toString();
	    //密码符合
;		//向服务器注册
		Server::getInstance()->RegisterClient(user_id,username,client);

		//向客户端返回登陆成功信息
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
		//密码不符合向客户端返回错误信息
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
