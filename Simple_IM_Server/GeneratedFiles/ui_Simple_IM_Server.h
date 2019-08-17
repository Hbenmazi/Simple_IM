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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Simple_IM_ServerClass
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Simple_IM_ServerClass)
    {
        if (Simple_IM_ServerClass->objectName().isEmpty())
            Simple_IM_ServerClass->setObjectName(QStringLiteral("Simple_IM_ServerClass"));
        Simple_IM_ServerClass->resize(600, 463);
        centralWidget = new QWidget(Simple_IM_ServerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(70, 10, 431, 371));
        tableWidget->setRowCount(0);
        Simple_IM_ServerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Simple_IM_ServerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        Simple_IM_ServerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Simple_IM_ServerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Simple_IM_ServerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Simple_IM_ServerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Simple_IM_ServerClass->setStatusBar(statusBar);

        retranslateUi(Simple_IM_ServerClass);

        QMetaObject::connectSlotsByName(Simple_IM_ServerClass);
    } // setupUi

    void retranslateUi(QMainWindow *Simple_IM_ServerClass)
    {
        Simple_IM_ServerClass->setWindowTitle(QApplication::translate("Simple_IM_ServerClass", "Simple_IM_Server", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Simple_IM_ServerClass", "user_id", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Simple_IM_ServerClass", "username", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Simple_IM_ServerClass", "ip", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Simple_IM_ServerClass", "port", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Simple_IM_ServerClass: public Ui_Simple_IM_ServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLE_IM_SERVER_H
