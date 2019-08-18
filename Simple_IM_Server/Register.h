#pragma once

#include<QMutex>
#include<QString>
#include<RemoteDB.h>
#include"qtcpsocket.h"
/**
 * @brief 服务器端完成注册功能的类
 * 描述： 使用单例模式
 */

class Register
{
public:
	
	static Register* getInstance();

	/**
	*Function: SignUp
	*Description: 写数据库以完成注册功能
	*param:用户信息
	*return;注册成功返回真
	*tableAccess;user
	*tableUpdate:user
	*/
	bool SignUp(QJsonObject userinfo,QTcpSocket* client) const;

private:
	static QMutex mutex;
	static Register* m_instance;
	RemoteDB* db;//数据库接口
	
	Register();
	~Register();
	


};

