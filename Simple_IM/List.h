#pragma once
#include <qobject.h>
#include "qvector.h"
#include "qjsonobject.h"
#include <QMutex>
#include "qstring.h"

/**
 * @brief 客户端处理好友列表的类
 */
class List :
	public QObject
{
	Q_OBJECT
public:
	static List* getInstance();
	
public slots:
	/**
	*Function: onListRefreshed
	*Description: 服务器返回好友列表时调用,并将列表信息交给ListGUI显示
	*param:
	*	-userArray:好友列表
	*/
	void onListRefreshed(QVector<QJsonObject> userArray);

	/**
	*Function: RefreshList
	*Description: 向服务器发出刷新列表请求
	*param:
	*return:发送成功返回真
	*/
	bool RefreshList();
	void setUsername(QString username);
	
private:
	static QMutex mutex;
	static List* m_instance;
	QString username;//本机用户名

	List();
	~List();
	
signals:
	void ListRefreshed(QVector<QJsonObject> userArray);
};
