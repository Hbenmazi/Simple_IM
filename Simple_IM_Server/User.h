#pragma once
#include"qstring.h"
#include"qtcpsocket.h"

/**
 * @brief ���������Ե�¼���û�
 */
class User
{
public:
	User();
	User(int user_id,QString username,QTcpSocket* socket);
	~User();

	void setUserId(int user_id);
	void setUsername(QString username);
	void setSocket(QTcpSocket* socket);
	void setFileSocket(QTcpSocket* fileSocket);
	int getUserId() const;
	QString getUsername() const;
	QTcpSocket* getSocket() const;
	QTcpSocket* getFileSocket() const;

private:
	int user_id;					//�û�ID
	QString username = "";			//�û���
	QTcpSocket* socket;				//��ͻ������ӵ��׽���
	QTcpSocket* fileSocket = NULL;	//�����ļ�������׽���
};

