/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *IP;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *PORT;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ConnectButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *DisconnectButton;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_8;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_6;
    QTextEdit *Rectext;
    QPushButton *Clear;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *Sendtext;
    QPushButton *Send;
    QWidget *widget_11;
    QVBoxLayout *verticalLayout_4;
    QPushButton *shutup;
    QPushButton *Closewiget;
    QLabel *zhuangtai;

    void setupUi(QWidget *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QString::fromUtf8("Server"));
        Server->resize(800, 600);
        verticalLayout_5 = new QVBoxLayout(Server);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget_3 = new QWidget(Server);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_10 = new QWidget(widget_3);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        verticalLayout_2 = new QVBoxLayout(widget_10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_5 = new QWidget(widget_10);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        widget = new QWidget(widget_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        IP = new QLineEdit(widget);
        IP->setObjectName(QString::fromUtf8("IP"));

        horizontalLayout->addWidget(IP);


        horizontalLayout_4->addWidget(widget);

        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        PORT = new QLineEdit(widget_2);
        PORT->setObjectName(QString::fromUtf8("PORT"));

        horizontalLayout_2->addWidget(PORT);


        horizontalLayout_4->addWidget(widget_2);


        verticalLayout_2->addWidget(widget_5);

        widget_4 = new QWidget(widget_10);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(233, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        ConnectButton = new QPushButton(widget_4);
        ConnectButton->setObjectName(QString::fromUtf8("ConnectButton"));

        horizontalLayout_3->addWidget(ConnectButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        DisconnectButton = new QPushButton(widget_4);
        DisconnectButton->setObjectName(QString::fromUtf8("DisconnectButton"));

        horizontalLayout_3->addWidget(DisconnectButton);

        horizontalSpacer = new QSpacerItem(233, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget_4);


        verticalLayout_3->addWidget(widget_10);

        widget_9 = new QWidget(widget_3);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_8 = new QHBoxLayout(widget_9);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        widget_8 = new QWidget(widget_9);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        verticalLayout = new QVBoxLayout(widget_8);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_7 = new QWidget(widget_8);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_6 = new QHBoxLayout(widget_7);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Rectext = new QTextEdit(widget_7);
        Rectext->setObjectName(QString::fromUtf8("Rectext"));

        horizontalLayout_6->addWidget(Rectext);

        Clear = new QPushButton(widget_7);
        Clear->setObjectName(QString::fromUtf8("Clear"));

        horizontalLayout_6->addWidget(Clear);


        verticalLayout->addWidget(widget_7);

        widget_6 = new QWidget(widget_8);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        Sendtext = new QLineEdit(widget_6);
        Sendtext->setObjectName(QString::fromUtf8("Sendtext"));

        horizontalLayout_5->addWidget(Sendtext);

        Send = new QPushButton(widget_6);
        Send->setObjectName(QString::fromUtf8("Send"));

        horizontalLayout_5->addWidget(Send);


        verticalLayout->addWidget(widget_6);


        horizontalLayout_8->addWidget(widget_8);

        widget_11 = new QWidget(widget_9);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        verticalLayout_4 = new QVBoxLayout(widget_11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        shutup = new QPushButton(widget_11);
        shutup->setObjectName(QString::fromUtf8("shutup"));

        verticalLayout_4->addWidget(shutup);

        Closewiget = new QPushButton(widget_11);
        Closewiget->setObjectName(QString::fromUtf8("Closewiget"));

        verticalLayout_4->addWidget(Closewiget);

        zhuangtai = new QLabel(widget_11);
        zhuangtai->setObjectName(QString::fromUtf8("zhuangtai"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(zhuangtai->sizePolicy().hasHeightForWidth());
        zhuangtai->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(zhuangtai);


        horizontalLayout_8->addWidget(widget_11);


        verticalLayout_3->addWidget(widget_9);


        verticalLayout_5->addWidget(widget_3);


        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QWidget *Server)
    {
        Server->setWindowTitle(QCoreApplication::translate("Server", "Server", nullptr));
        label->setText(QCoreApplication::translate("Server", "IP:", nullptr));
        label_2->setText(QCoreApplication::translate("Server", "\347\253\257\345\217\243:", nullptr));
        ConnectButton->setText(QCoreApplication::translate("Server", "\345\273\272\347\253\213\350\277\236\346\216\245", nullptr));
        DisconnectButton->setText(QCoreApplication::translate("Server", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        Clear->setText(QCoreApplication::translate("Server", "\346\270\205\345\261\217", nullptr));
        Send->setText(QCoreApplication::translate("Server", "\345\217\221\351\200\201", nullptr));
        shutup->setText(QCoreApplication::translate("Server", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        Closewiget->setText(QCoreApplication::translate("Server", "\345\205\263\351\227\255\347\252\227\345\217\243", nullptr));
        zhuangtai->setText(QCoreApplication::translate("Server", "\346\234\252\350\277\236\346\216\245\345\210\260\345\256\242\346\210\267\347\253\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
