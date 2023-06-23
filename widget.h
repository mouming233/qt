#ifndef WIDGET_H
#define WIDGET_H
#include<QTcpServer>
#include <QNetworkInterface>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDebug>
#include <QHostInfo>
#include <QRegExp>
#include <QNetworkInterface>
//#include <QDhcpClient>
#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QWidget>
#include<qpainter.h>
#include"title2.h"
#include<QTcpServer>
#include <QNetworkInterface>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDebug>
#include <QHostInfo>
#include <QRegExp>
#include <QNetworkInterface>
//#include <QDhcpClient>
#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include"QThread"
//#include"widget.h"
#include"QVBoxLayout"
#include"QtNetwork"
#include"QMessageBox"
#include <QtGlobal>
class Widget;
namespace Ui {
class Widget;
}

class MyThread : public QThread
{
    Q_OBJECT

signals:
    void showMessageSignal(const QString& title, const QString& message);
public:
    MyThread(Widget *parentWidget);
    void stop();

protected:
    void run();
    void handleProcessError(QProcess::ProcessError error);

private:
    Widget *widget;

    volatile bool stopped;
};


class MyThread2 : public QThread
{
    Q_OBJECT
public:
//    explicit MyThread2(QObject *parent = nullptr) : QThread(parent), Server(nullptr) {}
    MyThread2();
    MyThread2(Widget *parentWidget);
    void stop();
    void handleNewConnection();
    void handleReadyRead();
    QTcpServer*Server;

protected:
    void run();

private:
    Widget *widget;

    volatile bool stopped;
};


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent * ev);
    void ip_get();
    void ui_show(const QString &str,const QString &targetWidgetName);

    void restartPythonProgram();

    void showMessageSlot(const QString& title, const QString& message)
        {
            // 在主线程中显示 QMessageBox
            QMessageBox::critical(this, title, message);
        }

private slots:
    void on_open_clicked();

    void on_hide_clicked();

    void on_exit_clicked();

    void on_close_clicked();



    void sendzuobiao(int a);

    void on_wait_clicked();

    void on_restart_clicked();

signals:
    void ChangeUISLot();
    void tongshiSlot();

private:
    Ui::Widget *ui;
    title2 *t1=new title2;

    MyThread *thread;
    MyThread2 *thread2;


    QTcpSocket * tcpSocket;//用于传输数据的套接字

};

#endif // WIDGET_H
