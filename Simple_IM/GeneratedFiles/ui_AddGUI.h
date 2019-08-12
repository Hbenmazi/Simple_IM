/********************************************************************************
** Form generated from reading UI file 'AddGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGUI_H
#define UI_ADDGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddGUI
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *username_lineEdit;
    QPushButton *Add_pushButton;
    QLabel *Tip_label;

    void setupUi(QDialog *AddGUI)
    {
        if (AddGUI->objectName().isEmpty())
            AddGUI->setObjectName(QStringLiteral("AddGUI"));
        AddGUI->resize(355, 124);
        horizontalLayoutWidget = new QWidget(AddGUI);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(40, 20, 271, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        username_lineEdit = new QLineEdit(horizontalLayoutWidget);
        username_lineEdit->setObjectName(QStringLiteral("username_lineEdit"));

        horizontalLayout->addWidget(username_lineEdit);

        Add_pushButton = new QPushButton(AddGUI);
        Add_pushButton->setObjectName(QStringLiteral("Add_pushButton"));
        Add_pushButton->setGeometry(QRect(260, 90, 75, 23));
        Tip_label = new QLabel(AddGUI);
        Tip_label->setObjectName(QStringLiteral("Tip_label"));
        Tip_label->setGeometry(QRect(40, 90, 211, 16));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Tip_label->sizePolicy().hasHeightForWidth());
        Tip_label->setSizePolicy(sizePolicy);

        retranslateUi(AddGUI);

        QMetaObject::connectSlotsByName(AddGUI);
    } // setupUi

    void retranslateUi(QDialog *AddGUI)
    {
        AddGUI->setWindowTitle(QApplication::translate("AddGUI", "AddGUI", Q_NULLPTR));
        label->setText(QApplication::translate("AddGUI", "Search:", Q_NULLPTR));
        username_lineEdit->setInputMask(QString());
        username_lineEdit->setText(QString());
        username_lineEdit->setPlaceholderText(QApplication::translate("AddGUI", "username", Q_NULLPTR));
        Add_pushButton->setText(QApplication::translate("AddGUI", "Add", Q_NULLPTR));
        Tip_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddGUI: public Ui_AddGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGUI_H
