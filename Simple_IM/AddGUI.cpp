#include "AddGUI.h"
#include "qstring.h"
#include "ListGUI.h"
#include "qjsonobject.h"
AddGUI::AddGUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.Add_pushButton, SIGNAL(clicked()), this, SLOT(on_AddButton_clicked()));
	connect(&add, SIGNAL(AddContactSuccess(QJsonObject)), this,SLOT(onAddContactSuccess(QJsonObject)) );
	connect(&add, SIGNAL(AddContactFail(QJsonObject)), this,SLOT(onAddContactFail(QJsonObject)));
}

AddGUI::~AddGUI()
{

}

/**
*Function: on_AddButton_clicked
*Description: 点击按钮后触发,将用户填写的信息交给Add类处理
*/
void AddGUI::on_AddButton_clicked()
{
	QString username = qobject_cast<ListGUI*>(parentWidget())->getUsername();
	QString targetUsername = ui.username_lineEdit->text();
	add.AddContact(username, targetUsername);
}

/**
*Function: onAddContactSuccess
*Description: 收到添加成功的信号后，将信息打印到界面
*param:
	-data:服务器端返回的成功信息
*/
void AddGUI::onAddContactSuccess(QJsonObject data)
{
	ui.Tip_label->setText("Add contact successfully");
}

/**
*Function: onAddContactFail
*Description: 收到添加失败的信号后，将信息打印到界面
*param:
	-data:服务器端返回的错误信息
*/
void AddGUI::onAddContactFail(QJsonObject data)
{
	ui.Tip_label->setText(data.value("info").toString());
}


