#pragma once
#include <qobject.h>
#include <qtcpsocket.h>
#include <qmutex.h>
#include <QString>
#include "qjsonobject.h"

/**
 * @brief ��Ϊ�ͻ��˵�facade��
 * ������ʹ�õ���ģʽ���ͻ�����������ͨ��Client���������ͨ�ţ�ͬʱ������
 *       ��������Ϣ������Client���գ�Ȼ��ַ�����������д���
 */
class Client :
	public QObject
{
	Q_OBJECT

public:
	static Client* getInstance();
	QTcpSocket* getSocket() const;

	bool SendMessageToServer(QJsonDocument&  msg);

private:
	static Client* m_instance;
	static QMutex mutex;
	QTcpSocket* socket = NULL; //�����������ͨ�ŵ�TCP�׽���

	
	Client();
	~Client();
	
private slots:
	void socketConnected();
	void socketDisconnected();
	void socketReadyRead();

signals:
	void SignUpSuccess();
	void SignUpFail(QString info);
	void SignInSuccess(QString username);
	void SignInFail(QString info);
	void AddContactSuccess(QJsonObject data);
	void AddContactFail(QJsonObject data);
	void ListRefreshed(QJsonObject data);


	
};

