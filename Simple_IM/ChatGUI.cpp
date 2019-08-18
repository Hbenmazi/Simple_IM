#include "ChatGUI.h"
#include "qpushbutton.h"
#include "qlistwidget.h"
#include"Client.h"
ChatGUI::ChatGUI(QWidget *parent, QString username)
	: QDialog(parent)
{
	ui.setupUi(this);
	setUsername(username);

	//装载事件过滤器,使按回车可发送消息
	ui.msg_textEdit->installEventFilter(this);

	//初始化两个处理具体功能的类
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
*Description: 将窗口关闭后,ListGUI上对应按钮上的未读消息显示为0
*/
void ChatGUI::closeEvent(QCloseEvent * event)
{
	myButton->setText(getPeerUsername() + "(0)");
}

/**
*Function: eventFilter
*Description: 事件过滤器，设置按回车键发送消息
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
*Description: 点击发送按钮后将消息交给Chat处理
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
*Description: 点击ListGUI中对应该聊天窗口的按钮后，刷新该窗口的消息记录
*/
void ChatGUI::myButtonClicked()
{
	myButton = qobject_cast<QPushButton*>(QObject::sender());

	//设置对等方用户名
	setPeerUsername(myButton->text().section(QRegExp("[()]"), 0, 0).trimmed());//section函数将文本中括号以及括号中的内容截去
	ui.peerName_label->setText(myButton->text());

	//刷新聊天记录
	ui.log_listWidget->clear();//清空当前显示的消息
	chat->RefreshLog(getUsername(),getPeerUsername());//刷新记录

	this->show();
}

/**
*Function: onLogRefreshed
*Description: Chat触发该函数,刷新窗口中的聊天记录
*param:
	-dataArray:以Json格式储存的聊天消息向量
*/
void ChatGUI::onLogRefreshed(QVector<QJsonObject> dataArray)
{
	emit LogRefreshed(dataArray);
	
	//对于每一条聊天消息
	for (QJsonObject data : dataArray)
	{
		QString sender_name = data.value("sender_name").toString();

		//检查是否是本机用户和对等方的聊天记录
		if(sender_name == peerUsername || sender_name == username)
			displayLog(data);//打印至聊天窗口
	}

}

/**
*Function: displayLog
*Description: 将单条消息输出到聊天窗口
*param:
	-data:以Json格式储存的聊天消息
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

	QListWidgetItem *empty_item = new QListWidgetItem;//空行

	ui.log_listWidget->addItem(title_item);
	ui.log_listWidget->addItem(content_item);
	ui.log_listWidget->addItem(empty_item);

	ui.log_listWidget->scrollToBottom();//将滚动条滑至底端
}

void ChatGUI::onTransferFileButtonClicked()
{
	chat->onTransferFileButtonClicked(getUsername());//告诉服务器初始化传输文件服务器
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
