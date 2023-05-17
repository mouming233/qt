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
namespace Ui {
class Widget;
}

class MyThread : public QThread
{
public:
    MyThread();
    void stop();
protected:
    void run();

private:

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


private slots:
    void on_open_clicked();

    void on_hide_clicked();

    void on_exit_clicked();

    void on_close_clicked();

    void on_wait_clicked();


    void sendzuobiao();

signals:
    void ChangeUISLot();
    void tongshiSlot();

private:
    Ui::Widget *ui;
    title2 *t1=new title2;

    MyThread thread;


    QTcpSocket * tcpSocket;//用于传输数据的套接字



};

#endif // WIDGET_H
