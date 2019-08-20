#include "FileTransfer.h"
#include <QHostAddress>
#include <QTextCodec>
#include <QFileDialog>
#include"Client.h"
#include"qjsondocument.h"
FileTransfer::FileTransfer(QString peerUsername,QWidget *parent)
	: QDialog(parent)
{
	this->peerUsername = peerUsername;
	ui.setupUi(this);

	ui.progressBar->hide();

	totalSize_in = 0;
	byteReceived = 0;
	connect(ui.open_pushButton, SIGNAL(clicked()), this, SLOT(onOpenPushButtonClicked()));
	connect(ui.send_pushButton, SIGNAL(clicked()), this, SLOT(onSendPushButtonClicked()));
	connect(Client::getInstance(), SIGNAL(FileSocketReadyRead(QByteArray)), this, SLOT(onFileSocketReadyRead(QByteArray)));
}

FileTransfer::~FileTransfer()
{
}

void FileTransfer::setPeerUsername(QString peerUsername)
{
	this->peerUsername = peerUsername;
}

void FileTransfer::InitGUI()
{
	ui.open_pushButton->show();
	ui.send_pushButton->show();
	ui.progressBar->hide();
	ui.sendStatusLabel->clear();
	ui.recvStatusLabel->clear();
}

void FileTransfer::SendHeader()  //发送文件头信息
{
	//文件头发送成功后立即发送实际文件
	connect(Client::getInstance()->getFileSocket(), SIGNAL(bytesWritten(qint64)), this, SLOT(goOnSend(qint64)));

	byteToWrite = localFile->size();   //剩余数据的大小
	totalSize_out = localFile->size(); //文件总大小

	loadSize = 4 * 1024;  //每次发送数据的大小

	QDataStream out(&outBlock, QIODevice::WriteOnly);
	QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1);//从路径中获取文件名

	//将"isHeader"和对等方用户名写入文件头，以便服务器识别转发
	QString isHeader("header");
	out << qint64(0) << qint64(0)<<isHeader<<peerUsername<< currentFileName;

	totalSize_out += outBlock.size();  //总大小为文件大小加上文件名等信息大小
	byteToWrite += outBlock.size();

	//回到字节流起点，写好前面两个qint64，分别为总大小和文件名等信息大小
	out.device()->seek(0);  
	out << totalSize_out << qint64(outBlock.size());
	qDebug() << outBlock;

	//将读到的文件发送到套接字
	Client::getInstance()->getFileSocket()->write(outBlock);  

	//设置进度条
	ui.progressBar->show();
	ui.progressBar->setMaximum(totalSize_out);
	ui.progressBar->setValue(totalSize_out - byteToWrite);
}

/**
*Function: goOnSend
*Description: 分片传送实际文件内容
*param:
*	numBytes:上一个被发出的文件分片的字节数
*/
void FileTransfer::goOnSend(qint64 numBytes)  //开始发送文件内容
{
	byteToWrite -= numBytes;  //剩余数据大小

	//将读到的文件发送到套接字
	outBlock = localFile->read(qMin(byteToWrite, loadSize));
	Client::getInstance()->getFileSocket()->write(outBlock);  

	//设置进度条
	ui.progressBar->setMaximum(totalSize_out);
	ui.progressBar->setValue(totalSize_out - byteToWrite);

	if (byteToWrite == 0)  //发送完毕
	{
		ui.sendStatusLabel->setText("Finished");
		//文件头发送完成后断开信号槽
		Client::getInstance()->getFileSocket()->disconnect(this);
	}
}

//打开文件并获取文件名（包括路径）
void FileTransfer::onOpenPushButtonClicked()  
{
	ui.sendStatusLabel->setText("Opening...");
	ui.progressBar->setValue(0);  //非第一次发送

	loadSize = 0;
	byteToWrite = 0;
	totalSize_out = 0;
	outBlock.clear();

	fileName = QFileDialog::getOpenFileName(this);
	localFile = new QFile(fileName);
	localFile->open(QFile::ReadOnly);

	ui.sendStatusLabel->setText(QString("filename: %1").arg(fileName));
}

void FileTransfer::onSendPushButtonClicked()
{
    SendHeader();  
	ui.sendStatusLabel->setText(QString("transfering %1").arg(fileName));
}

void FileTransfer::onFileSocketReadyRead(QByteArray data)
{
	if (byteReceived == 0)  //才刚开始接收数据，此数据为文件信息
	{
		QDir *folder = new QDir;
		//判断创建文件夹是否存在
		bool exist = folder->exists("D:/File");

		if (!exist)//创建文件夹
			bool ok = folder->mkdir("D:/File");
		
		//读取文件信息
		QString temp;//临时字符串用来储存isHeader标识
		QDataStream in(data);
		in >> totalSize_in >> byteReceived >>temp>>peerUsername>> fileName_in;
		fileName_in = "D:/File/" + fileName_in;

		//新建文件
		newFile = new QFile(fileName_in);
		bool isopen = newFile->open(QFile::WriteOnly);
		qDebug() << "isopen" << isopen;

		QString status = "Your friend is sending a file to you:" + fileName_in;
		ui.open_pushButton->hide();
		ui.send_pushButton->hide();
		ui.recvStatusLabel->setText(status);
		show();
		ui.progressBar->show();
		ui.progressBar->setMaximum(totalSize_in);
		ui.progressBar->setValue(byteReceived);

	}
	else  //正式读取文件内容
	{
		inBlock = data;
		byteReceived += inBlock.size();
		qDebug()<<"write"<<newFile->write(inBlock);
		qDebug()<<"flush"<<newFile->flush();

		ui.progressBar->setMaximum(totalSize_in);
		ui.progressBar->setValue(byteReceived);
	}

}
