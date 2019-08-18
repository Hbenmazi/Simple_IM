#pragma once
#include "qstring.h"
#include <qobject.h>
#include "qjsonobject.h"
/**
 * @brief 客户端完成添加好友功能的类
 */

class Add:public QObject
{
	Q_OBJECT
public:
	Add();
	~Add();

	/**
	*Function: AddContact
	*Description: 向服务器发出添加好友请求
	*param:
		-username:发出请求的用户名
		-targetUsername:接收方的用户名
	*return;发出请求成功成功返回真
	*/
	bool AddContact(QString username,QString targetUsername) const;

private:

signals:
	void AddContactSuccess(QJsonObject data);
	void AddContactFail(QJsonObject data);

};

