/********************************************************************************
** Form generated from reading UI file 'LoginGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINGUI_H
#define UI_LOGINGUI_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginGUI
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *username_label;
    QLineEdit *username_lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *passward_label;
    QLineEdit *passward_lineEdit;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *SignUp_pushButton;
    QPushButton *SignIn_pushButton;

    void setupUi(QDialog *LoginGUI)
    {
        if (LoginGUI->objectName().isEmpty())
            LoginGUI->setObjectName(QStringLiteral("LoginGUI"));
        LoginGUI->resize(400, 300);
        verticalLayoutWidget = new QWidget(LoginGUI);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 20, 351, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        username_label = new QLabel(verticalLayoutWidget);
        username_label->setObjectName(QStringLiteral("username_label"));
        username_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(username_label);

        username_lineEdit = new QLineEdit(verticalLayoutWidget);
        username_lineEdit->setObjectName(QStringLiteral("username_lineEdit"));

        horizontalLayout_3->addWidget(username_lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        passward_label = new QLabel(verticalLayoutWidget);
        passward_label->setObjectName(QStringLiteral("passward_label"));
        passward_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(passward_label);

        passward_lineEdit = new QLineEdit(verticalLayoutWidget);
        passward_lineEdit->setObjectName(QStringLiteral("passward_lineEdit"));

        horizontalLayout_4->addWidget(passward_lineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        SignUp_pushButton = new QPushButton(verticalLayoutWidget);
        SignUp_pushButton->setObjectName(QStringLiteral("SignUp_pushButton"));

        horizontalLayout_5->addWidget(SignUp_pushButton);

        SignIn_pushButton = new QPushButton(verticalLayoutWidget);
        SignIn_pushButton->setObjectName(QStringLiteral("SignIn_pushButton"));

        horizontalLayout_5->addWidget(SignIn_pushButton);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(LoginGUI);

        QMetaObject::connectSlotsByName(LoginGUI);
    } // setupUi

    void retranslateUi(QDialog *LoginGUI)
    {
        LoginGUI->setWindowTitle(QApplication::translate("LoginGUI", "LoginGUI", Q_NULLPTR));
        username_label->setText(QApplication::translate("LoginGUI", "username:", Q_NULLPTR));
        passward_label->setText(QApplication::translate("LoginGUI", "passward:", Q_NULLPTR));
        SignUp_pushButton->setText(QApplication::translate("LoginGUI", "Sign Up", Q_NULLPTR));
        SignIn_pushButton->setText(QApplication::translate("LoginGUI", "Sign In", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginGUI: public Ui_LoginGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINGUI_H
