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

	/**
	*Function: SendMessageToClient
	*Description: ������Ϣ���ͻ���
	*param:
	*	-msg:��Ϣ����
	*	-socket:���ӿͻ��˵��׽���
	*return:���ͳɹ�������
	*/
	bool SendMessageToClient(QJsonDocument&  msg,QTcpSocket* socket);

	/**
	*Function: StartServer
	*Description: ��ʼ���������������ԣ���ʼ����
	*/
	void StartServer();

	/**
	*Function: RegisterClient
	*Description: ���µ�¼���û������allClients�б�
	*param:
	*	-user_id:�û�ID
	*	-username:�û���
	*	-client:���ӿͻ��˵��׽���
	*/
	void RegisterClient(int user_id, QString username, QTcpSocket* client);
	
	/**
	*Function: SearchUserBySocket
	*Description: ͨ����ͻ������ӵ��׽�����allClinets�б��в����û�
	*param:
	*	-socket:��ͻ������ӵ��׽���
	*return:ָ����û���ָ��
	*/
	User* SearchUserBySocket(QTcpSocket* socket);

	QVector<User*>*  getAllClients();

private:
	static QMutex mutex;
	static Server* m_instance;

	QTcpServer* chatServer;     //���������
	QTcpServer* fileServer;     //�ļ����������
	QVector<User*>* allClients; //Ŀǰ�Ѿ���½���û�
	QString peerUsername;       //�ļ�����ʱ���շ����û���

	Register* reg;	//����ע������
	Login* login;	//�����¼����
	Add* add;		//������Ӻ�������
	List* list;		//��������б�����
	Log* log;		//���������¼����


	Server();
	~Server();

private slots:
	/**
	*Function: newClientConnection
	*Description: ����server����������tcp����
	*/
	void newClientConnection();

	/*�����׽��ֺ� �����ļ��׽���״̬�ı��ᴥ�����º���*/
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

