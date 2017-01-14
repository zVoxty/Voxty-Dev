/********************************************************************************
** Form generated from reading UI file 'AppVox.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPVOX_H
#define UI_APPVOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppVoxClass
{
public:
    QWidget *centralWidget;
    QLabel *connectionStatus;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *connectToServer;
    QPushButton *disconnectToServer;
    QPushButton *chatButton;
    QPushButton *exit;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AppVoxClass)
    {
        if (AppVoxClass->objectName().isEmpty())
            AppVoxClass->setObjectName(QStringLiteral("AppVoxClass"));
        AppVoxClass->resize(600, 400);
        centralWidget = new QWidget(AppVoxClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        connectionStatus = new QLabel(centralWidget);
        connectionStatus->setObjectName(QStringLiteral("connectionStatus"));
        connectionStatus->setGeometry(QRect(9, 9, 134, 16));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(260, 120, 77, 112));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        connectToServer = new QPushButton(widget);
        connectToServer->setObjectName(QStringLiteral("connectToServer"));

        verticalLayout->addWidget(connectToServer);

        disconnectToServer = new QPushButton(widget);
        disconnectToServer->setObjectName(QStringLiteral("disconnectToServer"));

        verticalLayout->addWidget(disconnectToServer);

        chatButton = new QPushButton(widget);
        chatButton->setObjectName(QStringLiteral("chatButton"));

        verticalLayout->addWidget(chatButton);

        exit = new QPushButton(widget);
        exit->setObjectName(QStringLiteral("exit"));

        verticalLayout->addWidget(exit);

        AppVoxClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AppVoxClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        AppVoxClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(AppVoxClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AppVoxClass->setStatusBar(statusBar);

        retranslateUi(AppVoxClass);

        QMetaObject::connectSlotsByName(AppVoxClass);
    } // setupUi

    void retranslateUi(QMainWindow *AppVoxClass)
    {
        AppVoxClass->setWindowTitle(QApplication::translate("AppVoxClass", "AppVox", Q_NULLPTR));
        connectionStatus->setText(QApplication::translate("AppVoxClass", "Connection : No Connection", Q_NULLPTR));
        connectToServer->setText(QApplication::translate("AppVoxClass", "Connect", Q_NULLPTR));
        disconnectToServer->setText(QApplication::translate("AppVoxClass", "Disconnect", Q_NULLPTR));
        chatButton->setText(QApplication::translate("AppVoxClass", "Chat", Q_NULLPTR));
        exit->setText(QApplication::translate("AppVoxClass", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AppVoxClass: public Ui_AppVoxClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPVOX_H
