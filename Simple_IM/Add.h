#pragma once
#include "qstring.h"
#include <qobject.h>
#include "qjsonobject.h"
/**
 * @brief �ͻ��������Ӻ��ѹ��ܵ���
 */

class Add:public QObject
{
	Q_OBJECT
public:
	Add();
	~Add();

	/**
	*Function: AddContact
	*Description: �������������Ӻ�������
	*param:
		-username:����������û���
		-targetUsername:���շ����û���
	*return;��������ɹ��ɹ�������
	*/
	bool AddContact(QString username,QString targetUsername) const;

private:

signals:
	void AddContactSuccess(QJsonObject data);
	void AddContactFail(QJsonObject data);

};

