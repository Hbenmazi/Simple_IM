#include "Address.h"

QMutex Address::mutex;
Address*  Address::m_instance = NULL;


void Address::setIp(QString ip)
{
	ServerIP = ip;
}

void Address::setChatPort(int port)
{
	chatport = port;
}

void Address::setFilePort(int port)
{
	fileport = port;
}

QString Address::getServerIp() const
{
	return ServerIP;
}

int Address::getChatPort() const
{
	return chatport;
}

int Address::getFilePort() const
{
	return fileport;
}

Address::Address(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.ok_pushButton, SIGNAL(clicked()), this, SLOT(onOkButtonClicked()));
	connect(this, SIGNAL(finishSet()), logingui, SLOT(show()));
}

Address::~Address()
{
}

Address* Address::getInstance()//GOF-Singleton
{

	if (!m_instance)
	{
		QMutexLocker locker(&mutex);
		if (!m_instance)
		{
			m_instance = new Address;
		}

	}
	return m_instance;
}

void Address::onOkButtonClicked()
{
	setIp(ui.ip_lineEdit->text());
	setChatPort(ui.chatport_lineEdit->text().toInt());
	setFilePort(ui.fileport_lineEdit->text().toInt());
	close();
	logingui = new LoginGUI();
	logingui->show();
}