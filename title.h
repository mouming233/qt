#ifndef TITLE_H
#define TITLE_H
#include "title2.h"
#include <QWidget>
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
#include"zhong.h"

namespace Ui {
class title;
}

class title : public QWidget
{
    Q_OBJECT

public:
    explicit title(QWidget *parent = 0);
    ~title();
    void paintEvent(QPaintEvent * ev);

private slots:
    void on_pushButton_clicked();

private:
    title2 *t2;
    Ui::title *ui;
};

#endif // TITLE_H
