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
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent * ev);


private slots:
    void on_open_clicked();

private:
    Ui::Widget *ui;
    title2 *t1;



};

#endif // WIDGET_H
