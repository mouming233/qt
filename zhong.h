#ifndef ZHONG_H
#define ZHONG_H

#include <QWidget>
#include "title2.h"
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
#include"widget.h"
namespace Ui {
class zhong;
}

class zhong : public QWidget
{
    Q_OBJECT

public:
    explicit zhong(QWidget *parent = 0);
    ~zhong();
    void paintEvent(QPaintEvent * ev);

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::zhong *ui;
    title2 *t2;
};

#endif // ZHONG_H
