#include "server.h"
#include "ui_server.h"
#include<QTcpServer>
QString ip;
qint16 port;

Server::Server(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Server)
{
    ui->setupUi(this);




    server=new QTcpServer(this);


    connect(server,&QTcpServer::newConnection,this,slot_connect);

}

void Server::slot_connect(){

    conn=server->nextPendingConnection();


    ui->Rectext->append("有新的连接");

    connect(conn,&QTcpSocket::readyRead,this,[=](){
        QByteArray array =conn->readAll();
        qDebug() << "Received data from client: " << array;
        ui->Rectext->append(array);
    });

}

Server::~Server()
{
    delete ui;
}


void Server::on_ConnectButton_clicked()
{
    ip=ui->IP->text();
    port=ui->PORT->text().toInt();

    if(ui->IP->text().isEmpty()||ui->PORT->text().isEmpty()){

        QMessageBox::warning(this,"错误","请先输入ip地址和端口号");
        return;
    }
    server->close();

    if (!server->listen(QHostAddress(ip), port) ){
        qDebug() << "Server listen error: " << server->errorString();
        return;
    }
    qDebug() << "Server is listening...";

    conn=server->nextPendingConnection();

}

void Server::on_DisconnectButton_clicked()
{

}

void Server::on_Closewiget_clicked()
{
    this->close();
}

void Server::on_Clear_clicked()
{
    ui->Rectext->clear();
}

void Server::on_Send_clicked()
{
    if (!conn) {
        qDebug() << "No client connected.";
        return;
    }


    //发送数据
    conn->write(ui->Sendtext->text().toUtf8().data());
    qDebug() << "Sent data to client: " << ui->Sendtext->text();


    ui->Rectext->append("Me Say:"+ui->Sendtext->text());
    ui->Sendtext->clear();


}
