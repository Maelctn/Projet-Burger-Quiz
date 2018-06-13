/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *Layout_login;
    QHBoxLayout *layout_ip;
    QLabel *label_ip;
    QLineEdit *line_ip;
    QHBoxLayout *layout_username;
    QLabel *label_username;
    QLineEdit *line_username;
    QHBoxLayout *layout_password;
    QLabel *label_password;
    QLineEdit *line_password;
    QHBoxLayout *layout_name;
    QLabel *label_name;
    QLineEdit *line_name;
    QPushButton *button_login;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Layout_login = new QVBoxLayout();
        Layout_login->setSpacing(6);
        Layout_login->setObjectName(QStringLiteral("Layout_login"));
        layout_ip = new QHBoxLayout();
        layout_ip->setSpacing(6);
        layout_ip->setObjectName(QStringLiteral("layout_ip"));
        label_ip = new QLabel(groupBox);
        label_ip->setObjectName(QStringLiteral("label_ip"));

        layout_ip->addWidget(label_ip);

        line_ip = new QLineEdit(groupBox);
        line_ip->setObjectName(QStringLiteral("line_ip"));

        layout_ip->addWidget(line_ip);


        Layout_login->addLayout(layout_ip);

        layout_username = new QHBoxLayout();
        layout_username->setSpacing(6);
        layout_username->setObjectName(QStringLiteral("layout_username"));
        label_username = new QLabel(groupBox);
        label_username->setObjectName(QStringLiteral("label_username"));

        layout_username->addWidget(label_username);

        line_username = new QLineEdit(groupBox);
        line_username->setObjectName(QStringLiteral("line_username"));

        layout_username->addWidget(line_username);


        Layout_login->addLayout(layout_username);

        layout_password = new QHBoxLayout();
        layout_password->setSpacing(6);
        layout_password->setObjectName(QStringLiteral("layout_password"));
        label_password = new QLabel(groupBox);
        label_password->setObjectName(QStringLiteral("label_password"));

        layout_password->addWidget(label_password);

        line_password = new QLineEdit(groupBox);
        line_password->setObjectName(QStringLiteral("line_password"));
        line_password->setEchoMode(QLineEdit::Password);

        layout_password->addWidget(line_password);


        Layout_login->addLayout(layout_password);

        layout_name = new QHBoxLayout();
        layout_name->setSpacing(6);
        layout_name->setObjectName(QStringLiteral("layout_name"));
        label_name = new QLabel(groupBox);
        label_name->setObjectName(QStringLiteral("label_name"));

        layout_name->addWidget(label_name);

        line_name = new QLineEdit(groupBox);
        line_name->setObjectName(QStringLiteral("line_name"));

        layout_name->addWidget(line_name);


        Layout_login->addLayout(layout_name);

        button_login = new QPushButton(groupBox);
        button_login->setObjectName(QStringLiteral("button_login"));

        Layout_login->addWidget(button_login);


        verticalLayout->addLayout(Layout_login);


        horizontalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "LogIn", Q_NULLPTR));
        label_ip->setText(QApplication::translate("MainWindow", "IP de la base de donn\303\251e", Q_NULLPTR));
        label_username->setText(QApplication::translate("MainWindow", "Username de la base de donn\303\251e ", Q_NULLPTR));
        label_password->setText(QApplication::translate("MainWindow", "Mot de passe de la base de don\303\251e", Q_NULLPTR));
        label_name->setText(QApplication::translate("MainWindow", "Nom de la base de don\303\251e", Q_NULLPTR));
        button_login->setText(QApplication::translate("MainWindow", "LogIn", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
