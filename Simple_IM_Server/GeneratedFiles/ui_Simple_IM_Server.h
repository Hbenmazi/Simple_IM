/********************************************************************************
** Form generated from reading UI file 'Simple_IM_Server.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLE_IM_SERVER_H
#define UI_SIMPLE_IM_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Simple_IM_ServerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Simple_IM_ServerClass)
    {
        if (Simple_IM_ServerClass->objectName().isEmpty())
            Simple_IM_ServerClass->setObjectName(QStringLiteral("Simple_IM_ServerClass"));
        Simple_IM_ServerClass->resize(600, 400);
        menuBar = new QMenuBar(Simple_IM_ServerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Simple_IM_ServerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Simple_IM_ServerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Simple_IM_ServerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Simple_IM_ServerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Simple_IM_ServerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Simple_IM_ServerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Simple_IM_ServerClass->setStatusBar(statusBar);

        retranslateUi(Simple_IM_ServerClass);

        QMetaObject::connectSlotsByName(Simple_IM_ServerClass);
    } // setupUi

    void retranslateUi(QMainWindow *Simple_IM_ServerClass)
    {
        Simple_IM_ServerClass->setWindowTitle(QApplication::translate("Simple_IM_ServerClass", "Simple_IM_Server", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Simple_IM_ServerClass: public Ui_Simple_IM_ServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLE_IM_SERVER_H
