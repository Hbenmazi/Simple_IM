#pragma once
#include <qobject.h>
#include<qmutex.h>
#include<qtcpserver.h>


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

	void StartServer();

private:
	static QMutex mutex;
	static Server* m_instance;

	QTcpServer*             chatServer;//���ڼ���tcp���ӵĽ���
	QVector<QTcpSocket*>*   allClients;//Ŀǰ�Ѿ��������ӵ��׽���

	Server();
	~Server();

private slots:
	void newClientConnection();
	void socketDisconnected();
	void socketReadyRead();
	void socketStateChanged(QAbstractSocket::SocketState stste);


};

