#pragma once

#include <QDialog>
#include "ui_FileTransfer.h"
#include "qfile.h"

/**
 * @brief ��Ϊ�ͻ�������ļ����书�ܵ���
 */
class FileTransfer : public QDialog
{
	Q_OBJECT

public:
	FileTransfer(QString peerUsername = "",QWidget *parent = Q_NULLPTR);
	~FileTransfer();
	void setPeerUsername(QString peerUsername);
	void InitGUI();


public slots:
	void SendHeader();      //�����ļ�ͷ��Ϣ

	/**
	*Function: goOnSend
	*Description: ��Ƭ����ʵ���ļ�����
	*param:
	*	numBytes:��һ�����������ļ���Ƭ���ֽ���
	*/
	void goOnSend(qint64 numBytes);  //�����ļ�����
	void onOpenPushButtonClicked();
	void onSendPushButtonClicked();
	void onFileSocketReadyRead(QByteArray data);
	
private:
	Ui::FileTransfer ui;
	QString peerUsername;//���շ��û���
	QFile *localFile;
	QString fileName;  //�ļ�·��

	/*��������Ϊ���Ͷ���Ҫ������*/
	QByteArray outBlock;  //�ִδ��Ļ�����
	qint64 loadSize;      //ÿ�η������ݵĴ�С
	qint64 byteToWrite;   //ʣ�����ݴ�С
	qint64 totalSize_out; //�ļ��ܴ�С

	/*��������Ϊ���ն���Ҫ������*/
	QFile *newFile;
	QByteArray inBlock;	  //�ִν��ջ�����
	QString fileName_in;  //�����ļ���·��
	qint64 totalSize_in;  //�ܹ���Ҫ���͵��ļ���С���ļ�����&�ļ�����Ϣ��
	qint64 byteReceived;  //�Ѿ����͵Ĵ�С


};
