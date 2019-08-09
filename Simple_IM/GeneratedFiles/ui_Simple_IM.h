/********************************************************************************
** Form generated from reading UI file 'Simple_IM.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLE_IM_H
#define UI_SIMPLE_IM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Simple_IMClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Email_label;
    QLineEdit *Email_lineEdit;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Nickname_label;
    QLineEdit *Nickname_lineEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *Username_label;
    QLineEdit *Username_lineEdit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Passward_label;
    QLineEdit *Passward_lineEdit;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Passward_2_label;
    QLineEdit *Passward_2_lineEdit;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *SignIn_pushButton;
    QPushButton *SignUp_pushButton;
    QLabel *Tip_label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Simple_IMClass)
    {
        if (Simple_IMClass->objectName().isEmpty())
            Simple_IMClass->setObjectName(QStringLiteral("Simple_IMClass"));
        Simple_IMClass->resize(499, 382);
        centralWidget = new QWidget(Simple_IMClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget_5 = new QWidget(centralWidget);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(100, 191, 301, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        Email_label = new QLabel(horizontalLayoutWidget_5);
        Email_label->setObjectName(QStringLiteral("Email_label"));
        Email_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(Email_label);

        Email_lineEdit = new QLineEdit(horizontalLayoutWidget_5);
        Email_lineEdit->setObjectName(QStringLiteral("Email_lineEdit"));
        Email_lineEdit->setMaxLength(32767);

        horizontalLayout_5->addWidget(Email_lineEdit);

        horizontalLayoutWidget_4 = new QWidget(centralWidget);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(100, 161, 301, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        Nickname_label = new QLabel(horizontalLayoutWidget_4);
        Nickname_label->setObjectName(QStringLiteral("Nickname_label"));
        Nickname_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(Nickname_label);

        Nickname_lineEdit = new QLineEdit(horizontalLayoutWidget_4);
        Nickname_lineEdit->setObjectName(QStringLiteral("Nickname_lineEdit"));

        horizontalLayout_4->addWidget(Nickname_lineEdit);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(100, 70, 301, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Username_label = new QLabel(horizontalLayoutWidget);
        Username_label->setObjectName(QStringLiteral("Username_label"));
        Username_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(Username_label);

        Username_lineEdit = new QLineEdit(horizontalLayoutWidget);
        Username_lineEdit->setObjectName(QStringLiteral("Username_lineEdit"));

        horizontalLayout->addWidget(Username_lineEdit);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(100, 101, 301, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Passward_label = new QLabel(horizontalLayoutWidget_2);
        Passward_label->setObjectName(QStringLiteral("Passward_label"));
        Passward_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(Passward_label);

        Passward_lineEdit = new QLineEdit(horizontalLayoutWidget_2);
        Passward_lineEdit->setObjectName(QStringLiteral("Passward_lineEdit"));

        horizontalLayout_2->addWidget(Passward_lineEdit);

        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(100, 131, 301, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Passward_2_label = new QLabel(horizontalLayoutWidget_3);
        Passward_2_label->setObjectName(QStringLiteral("Passward_2_label"));
        Passward_2_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(Passward_2_label);

        Passward_2_lineEdit = new QLineEdit(horizontalLayoutWidget_3);
        Passward_2_lineEdit->setObjectName(QStringLiteral("Passward_2_lineEdit"));

        horizontalLayout_3->addWidget(Passward_2_lineEdit);

        horizontalLayoutWidget_6 = new QWidget(centralWidget);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(100, 260, 301, 41));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        SignIn_pushButton = new QPushButton(horizontalLayoutWidget_6);
        SignIn_pushButton->setObjectName(QStringLiteral("SignIn_pushButton"));

        horizontalLayout_6->addWidget(SignIn_pushButton);

        SignUp_pushButton = new QPushButton(horizontalLayoutWidget_6);
        SignUp_pushButton->setObjectName(QStringLiteral("SignUp_pushButton"));

        horizontalLayout_6->addWidget(SignUp_pushButton);

        Tip_label = new QLabel(centralWidget);
        Tip_label->setObjectName(QStringLiteral("Tip_label"));
        Tip_label->setGeometry(QRect(100, 230, 301, 20));
        Tip_label->setAlignment(Qt::AlignCenter);
        Simple_IMClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Simple_IMClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 499, 23));
        Simple_IMClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Simple_IMClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Simple_IMClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Simple_IMClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Simple_IMClass->setStatusBar(statusBar);

        retranslateUi(Simple_IMClass);

        QMetaObject::connectSlotsByName(Simple_IMClass);
    } // setupUi

    void retranslateUi(QMainWindow *Simple_IMClass)
    {
        Simple_IMClass->setWindowTitle(QApplication::translate("Simple_IMClass", "Simple_IM", Q_NULLPTR));
        Email_label->setText(QApplication::translate("Simple_IMClass", "Email:", Q_NULLPTR));
        Nickname_label->setText(QApplication::translate("Simple_IMClass", "Nickname:", Q_NULLPTR));
        Username_label->setText(QApplication::translate("Simple_IMClass", "Username:", Q_NULLPTR));
        Passward_label->setText(QApplication::translate("Simple_IMClass", "Passward:", Q_NULLPTR));
        Passward_lineEdit->setInputMask(QString());
        Passward_2_label->setText(QApplication::translate("Simple_IMClass", "Confirm Passward:", Q_NULLPTR));
        SignIn_pushButton->setText(QApplication::translate("Simple_IMClass", "Sign In", Q_NULLPTR));
        SignUp_pushButton->setText(QApplication::translate("Simple_IMClass", "Sign Up", Q_NULLPTR));
        Tip_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Simple_IMClass: public Ui_Simple_IMClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLE_IM_H
