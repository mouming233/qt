#include "widget.h"
#include "ui_widget.h"
#include"QVBoxLayout"
#include"QtNetwork"
#include"QMessageBox"

QString ip,fu_ip;
qint16 port,fu_port;
QStringList validIPs;
QRegularExpression ipRegex("^\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}$");

QProcess *process;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
//    t1=new title2(this);
    t1->setParent(this);
    QVBoxLayout* layout = new QVBoxLayout(this);
   layout->addWidget(t1);
//   connect(t1,&title2::clicked,this,&Widget::ChangeUISLot);
   connect(t1,&title2::clicked123,this,[=](){
       emit ChangeUISLot();
   });
   //设置垂直布局间隙
   layout->setSpacing(0);
   layout->setMargin(0);


   Widget::ip_get();

   ui->open->setEnabled(true);
   ui->close->setEnabled(false);

//   QTcpSocket *tcpSocket;
    tcpSocket=new QTcpSocket(this);

    connect(tcpSocket,&QTcpSocket::disconnected,[=](){
        ui->open->setEnabled(true);
        ui->close->setEnabled(false);
    });
    ui->fuIP->setText("192.168.1.123");
    ui->fuPort->setText("8888");

    thread.start();
    connect(ui->get,&QPushButton::clicked,this,&Widget::sendzuobiao);
    connect(ui->wait,&QPushButton::clicked,this,&Widget::sendzuobiao);
    connect(ui->put,&QPushButton::clicked,this,&Widget::sendzuobiao);


}
void Widget::ip_get(){
    int flag;
//      必须使用连接，来排除虚拟机的干扰
    foreach (const QNetworkInterface &iface, QNetworkInterface::allInterfaces()) {
        if (iface.flags().testFlag(QNetworkInterface::IsUp) && !iface.flags().testFlag(QNetworkInterface::IsLoopBack)){
            QString name = iface.name();
//            qDebug()<<name;
            if (name.contains("wireless") || name.contains("WiFi")) {
                qDebug() << "Wireless Adapter name: " << iface.humanReadableName();
                flag =1;
            } else {
//                qDebug() << "Wired Adapter name: " << iface.humanReadableName();
                flag=0;
            }
            foreach (const QNetworkAddressEntry &entry, iface.addressEntries()){
                ip = entry.ip().toString();

                if (ipRegex.match(ip).hasMatch()&&flag==1){
                     qDebug() << "ip: " <<ip;
                     ui->keIP->setText(ip);
                     qDebug()<<"";
                }
            }
        }
    }




}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent * ev)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap("://background1.jpg"),QRect());
}

void Widget::on_open_clicked()
{
    fu_ip=ui->fuIP->text();
    fu_port=ui->fuPort->text().toInt();


    tcpSocket->connectToHost(fu_ip,fu_port);

    if(ui->fuIP->text().isEmpty()||ui->fuPort->text().isEmpty()){

        QMessageBox::warning(this,"错误","请先输入ip地址和端口号");
        return;
    }

    if(tcpSocket->waitForConnected(3000)){
        qDebug()<<"connected!";
        ui->open->setEnabled(false);
        ui->close->setEnabled(true);

        port=tcpSocket->localPort();
        ui->kePort->setText(QString::number(port));

    }else {
        qDebug() << "Could not connect!";
        return;
    }

    qDebug() << "Server IP is: "<< tcpSocket->peerAddress()<<"\nPORT is: "<<tcpSocket->peerPort();


}

void Widget::on_hide_clicked()
{
    emit tongshiSlot();
}

void Widget::on_exit_clicked()
{
    this->close();
}

void Widget::on_close_clicked()
{
    tcpSocket->close();
    if(tcpSocket->state()==QAbstractSocket::UnconnectedState){
        qDebug()<<"Connection closed!";
        QMessageBox::information(this, "成功", "连接已关闭");

    }else{
        QMessageBox::warning(this, "错误", "无法关闭连接");

    }
}


void MyThread::run()
{
    // 创建QProcess对象
    process = new QProcess();

    // 启动Python程序
    QString program = "python";
    QStringList arguments = QStringList() << "./tu/camera.py"<<fu_ip;
    process->start(program, arguments);


    // 等待程序启动
    if (process->waitForStarted()){
        qDebug() << "Python程序已启动";
    }else{
        qDebug() << "Python程序启动失败";
    }
}


void MyThread::stop()
{
//    flag3=0;
    process->kill();

    //一般会等待程序正常结束
    //process->terminate(); // 发送SIGTERM信号
    // 等待进程结束
    if (process->waitForFinished(5000)){
        qDebug() << "Python程序已结束";
    } else {
        qDebug() << "Python程序无法结束";
    }
    stopped = true;

}
MyThread::MyThread()
{
    stopped = false;
}

void Widget::on_wait_clicked()
{

}
void Widget::sendzuobiao(){
    float a[2];
    a[0]=ui->wait_x->text().toFloat();
    a[1]=ui->wait_y->text().toFloat();

    QString coordinateString=QString("zuobiao/%1/%2").arg(a[0]).arg(a[1]);

    QByteArray coordinateByte=coordinateString.toUtf8();

    tcpSocket->write(coordinateByte);

}

