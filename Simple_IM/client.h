#pragma once
#include <qobject.h>
#include <qtcpsocket.h>
#include <qmutex.h>
#include <QString>
#include "qjsonobject.h"
#include "qvector.h"
/**
 * @brief 作为客户端的facade类
 * 描述：使用单例模式，客户端中其它类通过Client类与服务器通信，同时服务器
 *       发出的消息首先由Client接收，然后分发给其它类进行处理
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
	QTcpSocket* socket = NULL; //与服务器进行通信的TCP套接字
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

