#include "ChatGUI.h"
#include "qpushbutton.h"
#include "qlistwidget.h"
#include"Client.h"
ChatGUI::ChatGUI(QWidget *parent, QString username)
	: QDialog(parent)
{
	ui.setupUi(this);
	setUsername(username);

	//װ���¼�������,ʹ���س��ɷ�����Ϣ
	ui.msg_textEdit->installEventFilter(this);

	//��ʼ������������幦�ܵ���
	chat = new Chat();
	fileTransfer = new FileTransfer();

	//connect
	connect(ui.send_pushButton, SIGNAL(clicked()), this, SLOT(onNewMsgSended()));
	connect(ui.transerFile_pushButton, SIGNAL(clicked()), this, SLOT(onTransferFileButtonClicked()));
	connect(this, SIGNAL(NewMsgSended(QString, QString, QString)), chat, SLOT(onNewMsgSended(QString, QString, QString)));
	connect(chat, SIGNAL(LogRefreshed(QVector<QJsonObject>)), this, SLOT(onLogRefreshed(QVector<QJsonObject>)));
}

ChatGUI::~ChatGUI()
{
}

void ChatGUI::setUsername(QString username)
{
	this->username = username;
}

void ChatGUI::setPeerUsername(QString peerUsername)
{
	this->peerUsername = peerUsername;
	fileTransfer->setPeerUsername(peerUsername);
	
}

QString ChatGUI::getUsername() const
{
	return username;
}

QString ChatGUI::getPeerUsername() const
{
	return peerUsername;
}

/**
*Function: closeEvent
*Description: �����ڹرպ�,ListGUI�϶�Ӧ��ť�ϵ�δ����Ϣ��ʾΪ0
*/
void ChatGUI::closeEvent(QCloseEvent * event)
{
	myButton->setText(getPeerUsername() + "(0)");
}

/**
*Function: eventFilter
*Description: �¼������������ð��س���������Ϣ
*/
bool ChatGUI::eventFilter(QObject * obj, QEvent * e)
{
	Q_ASSERT(obj == ui.msg_textEdit);
	if (e->type() == QEvent::KeyPress)
	{
		QKeyEvent *eventkey = static_cast<QKeyEvent *>(e);
		if (eventkey->key() == Qt::Key_Return || eventkey->key() == Qt::Key_Enter)
		{
			onNewMsgSended();
			return true;
		}
		else if ((eventkey->key() == Qt::Key_Return || eventkey->key() == Qt::Key_Enter) && (eventkey->modifiers() & Qt::ControlModifier))
		{
			QString str = ui.msg_textEdit->toPlainText();
			str = str + "\r\n";
			ui.msg_textEdit->setPlainText(str);
			return true;
		}

	}
	return QObject::eventFilter(obj, e);
}

/**
*Function: onNewMsgSended
*Description: ������Ͱ�ť����Ϣ����Chat����
*/
void ChatGUI::onNewMsgSended()
{
	QString username = getUsername();
	QString targetUsername = getPeerUsername();
	QString content = ui.msg_textEdit->toPlainText();

	emit NewMsgSended(username, targetUsername, content);
	ui.msg_textEdit->clear();
}

/**
*Function: myButtonClicked
*Description: ���ListGUI�ж�Ӧ�����촰�ڵİ�ť��ˢ�¸ô��ڵ���Ϣ��¼
*/
void ChatGUI::myButtonClicked()
{
	myButton = qobject_cast<QPushButton*>(QObject::sender());

	//���öԵȷ��û���
	setPeerUsername(myButton->text().section(QRegExp("[()]"), 0, 0).trimmed());//section�������ı��������Լ������е����ݽ�ȥ
	ui.peerName_label->setText(myButton->text());

	//ˢ�������¼
	ui.log_listWidget->clear();//��յ�ǰ��ʾ����Ϣ
	chat->RefreshLog(getUsername(),getPeerUsername());//ˢ�¼�¼

	this->show();
}

/**
*Function: onLogRefreshed
*Description: Chat�����ú���,ˢ�´����е������¼
*param:
	-dataArray:��Json��ʽ�����������Ϣ����
*/
void ChatGUI::onLogRefreshed(QVector<QJsonObject> dataArray)
{
	emit LogRefreshed(dataArray);
	
	//����ÿһ��������Ϣ
	for (QJsonObject data : dataArray)
	{
		QString sender_name = data.value("sender_name").toString();

		//����Ƿ��Ǳ����û��ͶԵȷ��������¼
		if(sender_name == peerUsername || sender_name == username)
			displayLog(data);//��ӡ�����촰��
	}

}

/**
*Function: displayLog
*Description: ��������Ϣ��������촰��
*param:
	-data:��Json��ʽ�����������Ϣ
*/
void ChatGUI::displayLog(QJsonObject data)
{
	QString sender_name = data.value("sender_name").toString();
	QString time = data.value("time").toString();
	QString title = sender_name + "   " + time;
	QString content = data.value("content").toString();

	QListWidgetItem *title_item = new QListWidgetItem;
	title_item->setText(title);

	QListWidgetItem *content_item = new QListWidgetItem;
	content_item->setText(content);

	QListWidgetItem *empty_item = new QListWidgetItem;//����

	ui.log_listWidget->addItem(title_item);
	ui.log_listWidget->addItem(content_item);
	ui.log_listWidget->addItem(empty_item);

	ui.log_listWidget->scrollToBottom();//�������������׶�
}

void ChatGUI::onTransferFileButtonClicked()
{
	chat->onTransferFileButtonClicked(getUsername());//���߷�������ʼ�������ļ�������
	fileTransfer->show();
}


void ChatGUI::keyPressEvent(QKeyEvent *event)
{
	switch (event->key()) 
	{
		case Qt::Key_Return:
		    onNewMsgSended();
			break;

	   default:
			break;
	}
}
