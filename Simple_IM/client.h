#pragma once
#include <qobject.h>
#include <qtcpsocket.h>
#include <qmutex.h>
#include <QString>
#include "qjsonobject.h"
#include "qvector.h"
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
	QTcpSocket* getFileSocket() const;

	bool SendMessageToServer(QJsonDocument&  msg);
	bool SendMessageToFileServer(QJsonDocument& msg);
	void handleMeaasge(QString msg);

private:
	static Client* m_instance;
	static QMutex mutex;
	QTcpSocket* socket = NULL; //�����������ͨ�ŵ�TCP�׽���
	QTcpSocket* fileSocket = NULL;

	
	Client();
	~Client();
	
public slots:
	void socketConnected();
	void socketDisconnected();
	void socketReadyRead();
	void fileSocketReadyRead();
	void onSignInSuccess();

signals:
	void SignUpSuccess();
	void SignUpFail(QString info);
	void SignInSuccess(QString username);
	void SignInFail(QString info);
	void AddContactSuccess(QJsonObject data);
	void AddContactFail(QJsonObject data);
	void ListRefreshed(QVector<QJsonObject> dataArray);
	void LogRefreshed(QVector<QJsonObject> dataArray);
	void FileSocketReadyRead(QByteArray data);


	
};

