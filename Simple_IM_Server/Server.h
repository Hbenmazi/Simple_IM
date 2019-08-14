#pragma once
#include <qobject.h>
#include<qmutex.h>
#include<qtcpserver.h>
#include"qstring.h"
#include"User.h"
#include"Register.h"
#include"Login.h"
#include"Add.h"
#include"List.h"
#include"Log.h"
/**
 * @brief ��Ϊ��������facade��
 * ������ʹ�õ���ģʽ������������������ͨ��Server����ͻ���ͨ�ţ�ͬʱ������
 *       ���յ���Ϣ������Server���գ�Ȼ��ַ�����������д���
 */
class Server :
	public QObject
{
	Q_OBJECT

public:
	static Server* getInstance();
	bool SendMessageToClient(QJsonDocument&  msg,QTcpSocket* socket);
	void StartServer();
	void RegisterClient(int user_id, QString username, QTcpSocket* client);
	User* SearchUserBySocket(QTcpSocket* socket);
	QVector<User*>*  getAllClients();

private:
	static QMutex mutex;
	static Server* m_instance;

	QTcpServer* chatServer;//���ڼ���tcp���ӵĽ���
	QTcpServer* fileServer;//���ڴ����ļ�
	QVector<User*>* allClients;//Ŀǰ�Ѿ���½���û�
	QString peerUsername;//�ļ�����ʱ���շ����û���

	Register* reg;
	Login* login;
	Add* add;
	List* list;
	Log* log;


	Server();
	~Server();

private slots:
	void newClientConnection();
	void socketDisconnected();
	void socketReadyRead();
	void socketStateChanged(QAbstractSocket::SocketState state);
	void fileSocketDisconnected();
	void fileSocketReadyRead();
	void fileSocketStateChanged(QAbstractSocket::SocketState state);

signals:
	void newClientSignIn(int user_id, QString username, QTcpSocket* client);
	void ClientLogOut(int user_id, QString username, QTcpSocket* client);

};

