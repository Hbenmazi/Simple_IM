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

	/**
	*Function:       SendMessageToServer
	*Description:    发送消息至聊天服务器
	*param:
		-msg: JSONDOC格式的消息
	*/
	bool SendMessageToServer(QJsonDocument&  msg);

	/**
	*Function:       SendMessageToFileServer
	*Description:    发送消息至文件传输服务器
	*param:
		-msg: JSONDOC格式的消息
	*/
	bool SendMessageToFileServer(QJsonDocument& msg);

	/**
	*Function:       handleMeaasge
	*Description:    处理服务器发来的消息
	*param:
		-msg:消息内容
	*/
	void handleMeaasge(QString msg);

private:
	static Client* m_instance;
	static QMutex mutex;
	QTcpSocket* socket = NULL; //与服务器进行通信，完成聊天功能的TCP套接字
	QTcpSocket* fileSocket = NULL;//与服务器进行通信，完成文件传输功能的TCP套接字

	
	Client();
	~Client();
	
public slots:
	void socketConnected();
	void socketDisconnected();
	void socketReadyRead();
	void fileSocketReadyRead();
	void onSignInSuccess();

signals:
	//根据服务器传来的消息类型，发送以下信号，完成各个功能的类会接收对应的消息并处理
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

