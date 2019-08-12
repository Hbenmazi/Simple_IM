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

void AddGUI::onAddContactSuccess(QJsonObject data)
{
	ui.Tip_label->setText("Add contact successfully");
}

void AddGUI::onAddContactFail(QJsonObject data)
{
	ui.Tip_label->setText(data.value("info").toString());
}

void AddGUI::on_AddButton_clicked()
{
	QString username = qobject_cast<ListGUI*>(parentWidget())->getUsername();
	QString targetUsername = ui.username_lineEdit->text();
	add.AddContact(username,targetUsername);
}
