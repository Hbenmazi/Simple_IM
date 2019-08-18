#pragma once
#include <qobject.h>
#include "qvector.h"
#include "qjsonobject.h"
#include <QMutex>
#include "qstring.h"

/**
 * @brief �ͻ��˴�������б����
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
	*Description: ���������غ����б�ʱ����,�����б���Ϣ����ListGUI��ʾ
	*param:
	*	-userArray:�����б�
	*/
	void onListRefreshed(QVector<QJsonObject> userArray);

	/**
	*Function: RefreshList
	*Description: �����������ˢ���б�����
	*param:
	*return:���ͳɹ�������
	*/
	bool RefreshList();
	void setUsername(QString username);
	
private:
	static QMutex mutex;
	static List* m_instance;
	QString username;//�����û���

	List();
	~List();
	
signals:
	void ListRefreshed(QVector<QJsonObject> userArray);
};
