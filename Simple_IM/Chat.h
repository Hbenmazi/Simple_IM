#pragma once
#include "qobject.h"
#include"qvector.h"
#include"qjsonobject.h"
/**
 * @brief �ͻ���������칦�ܵ���
 * ����:���ͻ��˷�������Ϣ���µ����촰��,���û����͵���Ϣ���͸�����������
 */
class Chat :public QObject
{
	Q_OBJECT

public:
	Chat();
	~Chat();

	/**
	*Function: RefreshLog
	*Description: ��������ύˢ�����촰�ڵ�����
	*param:
		-username:�����û���
		-peerUsername:�Եȷ��û���
	*/
	void RefreshLog(QString username, QString peerUsername);

public slots:
	/**
	*Function: onNewMsgSended
	*Description: �û�������ͻ�س��󣬽���Ϣ���͸�����������
	*param:
		-username:�����û���
		-peerUsername:�Եȷ��û���
		-content:��Ϣ����
	*/
	void onNewMsgSended(QString username, QString targetUsername, QString content);

	/**
	*Function: onLogRefreshed
	*Description: �յ����������͵������¼�󣬷��� LogRefreshed�źţ�����ChatGUI
	*param:
		-dataArray:��Json��ʽ�������Ϣ����
	*/
	void onLogRefreshed(QVector<QJsonObject> dataArray);

	/**
	*Function: onTransferFileButtonClicked
	*Description: ��������ļ���ť������Ϣ�����������������˻��ʼ�������ļ��ķ�����
	*param:
		-username:�����û���
	*/
	void onTransferFileButtonClicked(QString username);
	
signals:
	void LogRefreshed(QVector<QJsonObject> dataArray);

};

