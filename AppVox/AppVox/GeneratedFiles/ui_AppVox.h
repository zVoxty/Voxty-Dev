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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *connectToServer;
    QPushButton *disconnectToServer;
    QPushButton *exit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *inputText;
    QPushButton *submitText;
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
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(510, 260, 77, 83));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        connectToServer = new QPushButton(layoutWidget);
        connectToServer->setObjectName(QStringLiteral("connectToServer"));

        verticalLayout->addWidget(connectToServer);

        disconnectToServer = new QPushButton(layoutWidget);
        disconnectToServer->setObjectName(QStringLiteral("disconnectToServer"));

        verticalLayout->addWidget(disconnectToServer);

        exit = new QPushButton(layoutWidget);
        exit->setObjectName(QStringLiteral("exit"));

        verticalLayout->addWidget(exit);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 280, 216, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        inputText = new QLineEdit(widget);
        inputText->setObjectName(QStringLiteral("inputText"));

        horizontalLayout->addWidget(inputText);

        submitText = new QPushButton(widget);
        submitText->setObjectName(QStringLiteral("submitText"));

        horizontalLayout->addWidget(submitText);

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
        exit->setText(QApplication::translate("AppVoxClass", "Exit", Q_NULLPTR));
        submitText->setText(QApplication::translate("AppVoxClass", "Submit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AppVoxClass: public Ui_AppVoxClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPVOX_H
