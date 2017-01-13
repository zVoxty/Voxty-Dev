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
    QPushButton *exit;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *connectToServer;
    QPushButton *disconnectToServer;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AppVoxClass)
    {
        if (AppVoxClass->objectName().isEmpty())
            AppVoxClass->setObjectName(QStringLiteral("AppVoxClass"));
        AppVoxClass->resize(600, 400);
        centralWidget = new QWidget(AppVoxClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        exit = new QPushButton(centralWidget);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(10, 320, 75, 23));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 170, 77, 54));
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
        exit->setText(QApplication::translate("AppVoxClass", "Exit", Q_NULLPTR));
        connectToServer->setText(QApplication::translate("AppVoxClass", "Connect", Q_NULLPTR));
        disconnectToServer->setText(QApplication::translate("AppVoxClass", "Disconnect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AppVoxClass: public Ui_AppVoxClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPVOX_H
