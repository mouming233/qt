#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QTcpSocket> //通信套接字
#include <QFile>      //文件操作
#include <QHostAddress> //IP地址
#include <QMessageBox> //提示对话框
#include <QPainter>
#include <QDateTime>
#include <QElapsedTimer>//延时
#include <QtDebug>
#include <QThread>
#include <windows.h>
#include  <QDebug>
#include<QTcpServer>
QT_BEGIN_NAMESPACE
namespace Ui { class Server; }
QT_END_NAMESPACE

class Server : public QWidget
{
    Q_OBJECT

public:
    Server(QWidget *parent = nullptr);
    ~Server();
    void  slot_connect();

private slots:
    void on_ConnectButton_clicked();

    void on_DisconnectButton_clicked();

    void on_Closewiget_clicked();

    void on_Clear_clicked();

    void on_Send_clicked();



private:
    Ui::Server *ui;


    QTcpServer * server;//用于通信的套接字
    QTcpSocket * conn;//用于传输数据的套接字
};
#endif // SERVER_H
