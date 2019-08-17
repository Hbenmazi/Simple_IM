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

void ListGUI::onListRefreshed(QVector<QJsonObject> userArray)
{
	int friendlist_size = friendlist.size();
	for (int i = 0;i< friendlist_size;i++)
	{
		QPushButton* temp = friendlist.at(0);
		ui.list_verticalLayout->removeWidget(temp);
		friendlist.remove(0);
		temp->~QPushButton();
	}

	for (QJsonObject user : userArray)
	{
		QPushButton* button = new QPushButton(this);
		connect(button, SIGNAL(clicked()), chatDialog, SLOT(myButtonClicked()));

		button->setText(user.value("username").toString()+"(0)");
		friendlist.append(button);
		ui.list_verticalLayout->addWidget(button);
	}
	
}

void ListGUI::onLogRefreshed(QVector<QJsonObject> dataArray)
{
	for (QJsonObject data : dataArray)
	{
		QString sender_name = data.value("sender_name").toString();
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