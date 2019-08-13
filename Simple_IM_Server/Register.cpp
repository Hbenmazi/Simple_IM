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
*Description: 写数据库以完成注册功能
*param:用户信息
*return;注册成功返回真
*tableAccess;user
*tableUpdate:user
*/

bool Register::SignUp(QJsonObject userinfo,QTcpSocket* client) const
{
	//提取用户信息
	QString username = userinfo.value("username").toString();
	QString password = userinfo.value("password").toString();
	QString nickname = userinfo.value("nickname").toString();
	QString email = userinfo.value("email").toString();

	//初始化查询语句
	QSqlQuery query(db->getDB());

	//先查询用户名是否已经被注册
	if (query.exec("select * from user where username = \"" +username+ "\"") == false)//查询失败
	{
		//打印错误信息
		qDebug() << "Server Error(signup,select):";
		qDebug() << "\n\n" << query.lastError().text().toUtf8() << "\n\n";
		return 0;
	}
	
	//判断用户名是否存在
	if (query.size() == 0)
	{
		query.finish();//先完成上一次查询

		//更新user表,向客户端返回注册成功消息
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
			//更新失败，返回错误信息
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
		//用户名已经被注册
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
*Description: 构造函数，获取数据库对象以初始化成员
*/
Register::Register()
{
	db = RemoteDB::getInstance();
};

Register::~Register()
{

};