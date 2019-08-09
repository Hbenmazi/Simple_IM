#pragma once

#include<QMutex>
#include<QString>
#include<RemoteDB.h>
/**
 * @brief 服务器端完成注册功能的类
 * 描述： 使用单例模式
 */

class Register
{
public:
	
	static Register* getInstance();
	bool SignUp(QJsonObject userinfo) const;

private:
	static QMutex mutex;
	static Register* m_instance;
	RemoteDB* db;
	
	Register();
	


};

