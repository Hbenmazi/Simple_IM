#include "ListGUI.h"
#include "List.h"
#include "qvector.h"
ListGUI::ListGUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	addDialog = new AddGUI(this);
	chatDialog = new ChatGUI(this);
	addDialog->setModal(true);

	connect(chatDialog, SIGNAL(LogRefreshed(QVector<QJsonObject>)), this, SLOT(onLogRefreshed(QVector<QJsonObject>)));
	connect(ui.addcontacts_pushButton, SIGNAL(clicked()), this, SLOT(on_AddButton_clicked()));
	connect(List::getInstance(), SIGNAL(ListRefreshed(QVector<QJsonObject>)),this, SLOT(onListRefreshed(QVector<QJsonObject>)));
}

ListGUI::~ListGUI()
{
}

void ListGUI::setUsername(QString username)
{
	this->username = username;
	this->chatDialog->setUsername(username);
	ui.username_label->setText(username);
}

QString ListGUI::getUsername() const
{
	return username;
}

/**
*Function: onListRefreshed
*Description: 刷新好友列表
*param:
*	-userArray:好友列表
*/
void ListGUI::onListRefreshed(QVector<QJsonObject> userArray)
{

	//先清除列表中的所有按钮
	int friendlist_size = friendlist.size();
	for (int i = 0;i< friendlist_size;i++)
	{
		QPushButton* temp = friendlist.at(0);
		ui.list_verticalLayout->removeWidget(temp);
		friendlist.remove(0);
		temp->~QPushButton();
	}

	//将每一个好友加载到界面
	for (QJsonObject user : userArray)
	{
		//初始化按钮
		QPushButton* button = new QPushButton(this);
		connect(button, SIGNAL(clicked()), chatDialog, SLOT(myButtonClicked()));

		//设置文字，默认未读消息为0条
		button->setText(user.value("username").toString()+"(0)");

		//设置头像
		QString profile_index = user.value("profile_index").toString();
		QString path = QString(":/Simple_IM/Resources/head%1.jpg").arg(profile_index);
		QPixmap icon1(path);
		button->setFixedHeight(50);
		button->setIconSize(QSize(30,30));
		button->setIcon(icon1);

		//放入friendlist并显示到屏幕
		friendlist.append(button);
		ui.list_verticalLayout->addWidget(button);
	}
	
}

/**
*Function: onLogRefreshed
*Description: 更新未读消息条数
*param:
*	-dataArray:消息队列
*/
void ListGUI::onLogRefreshed(QVector<QJsonObject> dataArray)
{
	for (QJsonObject data : dataArray)
	{
		//获取发送方的姓名
		QString sender_name = data.value("sender_name").toString();

		//遍历所有按钮，如果发送方的用户名与按钮上的相同，则未读消息+1
		for (QPushButton* button : friendlist)
		{
			if (button->text().section(QRegExp("[()]"),0 , 0).trimmed() == sender_name)
			{
				int count = (button->text()).section(QRegExp("[()]"), 1, 1).trimmed().toInt();
				count++;
				button->setText(sender_name + "(" + QString::number(count,10) +")");
			}
		}
	}
}

void ListGUI::on_AddButton_clicked()
{
	addDialog->show();
}