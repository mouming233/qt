#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>
//#include <QObject>
//QtGlobal
#define TEXT_COLOR_1(STRING)         "<b>""<font color=purple>" STRING "</font>""</b>" "<font color=black> </font>"
#define TEXT_COLOR_2(STRING)         "<b>""<font color=blue>" STRING "</font>""</b>" "<font color=black> </font>"
#define TEXT_COLOR_3(STRING)         "<b>""<font color=green>" STRING "</font>""</b>" "<font color=black> </font>"

QString ip,fu_ip;
qint16 port,fu_port;
QStringList validIPs;
QRegularExpression ipRegex("^\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}$");
int b;
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
//   for(int i=0;i<20;i++)ui->textrec->append("nihao");

   Widget::ip_get();

   ui->open->setEnabled(true);
   ui->close->setEnabled(false);

//   QTcpSocket *tcpSocket;
    tcpSocket=new QTcpSocket(this);
    connect(ui->restart, &QPushButton::clicked, this, &Widget::restartPythonProgram);
    connect(tcpSocket,&QTcpSocket::disconnected,[=](){
        ui->open->setEnabled(true);
        ui->close->setEnabled(false);
    });
    ui->fuIP->setText("192.168.1.123");
    ui->fuPort->setText("8888");

    thread=new MyThread(this);
    thread2 = new MyThread2(this);

    connect(thread, &MyThread::showMessageSignal, this, &Widget::showMessageSlot);
//    thread->start();
    thread2->start();


    QButtonGroup *buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->get, 1);
    buttonGroup->addButton(ui->wait, 2);
    buttonGroup->addButton(ui->put, 3);

    connect(buttonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), this, [this](int id){
        sendzuobiao(id);
    });
}

//void Widget::restartPythonProgram()
//{
//    // 停止之前的 Python 程序进程（如果有）
//    if (process && process->state() == QProcess::Running) {
//        process->kill();
//        process->waitForFinished();
//    }

//    // 创建 QProcess 对象
//    process = new QProcess(this);
//    QByteArray uishow;

//    // 启动 Python 程序
//    QString program = "python";
//    QStringList arguments;
//    arguments << "../QTmodel/tu/camera.py" << "192.168.1.123";
//    process->start(program, arguments);
//}
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
void Widget:: ui_show(const QString &str,const QString &targetWidgetName){
    qDebug()<<"成功输入"<<str;
    if(targetWidgetName=="textrec")
    {ui->textrec->append(str);}
    else if(targetWidgetName=="zhuangtai")
    {ui->zhuangtai->setText(str);}
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
        QMessageBox::information(this,"状态","连接成功");
        ui->open->setEnabled(false);
        ui->close->setEnabled(true);

        port=tcpSocket->localPort();
        ui->kePort->setText(QString::number(port));

    }else {
        qDebug() << "Could not connect!";
        QMessageBox::critical(this,"状态","连接失败");
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

MyThread2::MyThread2(Widget *parentWidget)
{
    qDebug()<<"newnew2";
    widget = parentWidget;
    stopped = false;
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

void Widget::restartPythonProgram()
{
    while(thread->isRunning())
    {
        process->kill();

        //一般会等待程序正常结束
        //process->terminate(); // 发送SIGTERM信号
        // 等待进程结束
//        if (process->waitForFinished(5000)){
//            qDebug() << "Python程序已结束";
//        } else {
//            qDebug() << "Python程序无法结束";
//        }
        qDebug()<<"视频传输中止";
        thread->quit();
    }
//    thread->stop();
    thread=new MyThread(this);
    thread->start();
}
void MyThread::handleProcessError(QProcess::ProcessError error)
{

}
void MyThread::run()
{
        // 创建QProcess对象
        process = new QProcess(this);


        QString  uishow;


//        widget->ui_show("nihao");
        // 启动Python程序
        QString program = "python";
        QStringList arguments;
        arguments << "../QTmodel/tu/camera.py" << "192.168.1.123";
        process->start(program, arguments);

        // 等待程序启动
        if (process->waitForStarted()){
            qDebug() << "视频传输开启";
            uishow=TEXT_COLOR_1("视频传输启动");

            widget->ui_show(uishow,"textrec");
            if (process->state() == QProcess::Running){
                qDebug() << "External program is running.";
//                widget->ui_show("External program is running.");
            } else {
                qDebug() << "External program is not running.";
                widget->ui_show("External program is not running.","textrec");
                b=0;
            }


            process->waitForFinished();  // 等待进程完成

            QByteArray outputData = process->readAllStandardOutput();  // 获取标准输出数据
            QByteArray errorData = process->readAllStandardError();    // 获取标准错误数据
            QString output = QString::fromUtf8(outputData);  // 将输出数据转换为字符串
            QString error = QString::fromUtf8(errorData);    // 将错误数据转换为字符串
            qDebug() << "标准输出：" << output;
//            qDebug() << "标准错误：" << error;

            if (!error.isEmpty()) {
                    if (error.contains("TimeoutError")) {
                        qDebug() << "TCP connection timeout occurred.";
                        // 在这里处理 TCP 连接超时的情况

                        widget->ui_show("视频连接超时，请检查服务端是否成功开启视频传输线程","textrec");
//                        QMessageBox::critical(this,"错误","视频连接超时，请检查服务端是否成功开启视频传输线程");
                        emit showMessageSignal("错误", "连接超时");
//                        QString text=TEXT_COLOR_1("摄像头无法连接");
                        QString text="摄像头无法连接";
                        widget->ui_show(text,"zhuangtai");

                    }
                    else {
                        qDebug() << "Python program error:" << error;
                    }
                }




        }else {
            qDebug() << "Python程序启动失败";
            uishow="Python程序启动失败";

            widget->ui_show(uishow,"textrec");
            return;
        }

//        widget->ui_show(uishow);
        // 检查外部程序状态
        if (process->state() == QProcess::Running){
            qDebug() << "External program is running.";
        } else {
            qDebug() << "External program is not running.";
            QString text;
            text=TEXT_COLOR_1("视频传输终止");
            widget->ui_show(text,"textrec");
            b=0;
        }
        // 外部程序调用过程中的错误处理
//        connect(process, QOverload<QProcess::ProcessError>::of(&QProcess::error), this, [this](QProcess::ProcessError error){
//            // 处理错误
//        });
        // 连接 errorOccurred 信号到槽函数

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
//MyThread::MyThread()
//{
//    stopped = false;
//}
//MyThread2::MyThread2(Widget *parentWidget) : widget(parentWidget) {
//    // 其他初始化操作
//}
MyThread::MyThread(Widget *parentWidget) : widget(parentWidget) {
    // 其他初始化操作
}
MyThread2::MyThread2()
{

//    widget = new Widget();
    qDebug()<<"newnew3";
    stopped = false;
}
void MyThread2::run(){

        QTcpServer *server1=new QTcpServer();
        server1->listen(QHostAddress::Any,7777);
        connect(server1,&QTcpServer::newConnection,[=](){
           qDebug()<<"newconnection";
        });
    qDebug()<<"newnew";
}



void MyThread2::handleNewConnection(){

        qDebug()<<"connecting wait";
    QTcpSocket *clientSocket=Server->nextPendingConnection();
    QString ipAddress=clientSocket->peerAddress().toString();
    qDebug()<<"video connected by";
    connect(clientSocket,&QTcpSocket::readyRead,this,&MyThread2::handleReadyRead);
}

void MyThread2::handleReadyRead(){
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (clientSocket)
    {
        QByteArray requestData = clientSocket->readAll();
        widget->ui_show(requestData,"textrec");
    }
}

void Widget::sendzuobiao(int b){
    float a[2];
    if(b==1)
    {
        a[0]=ui->get_x->text().toFloat();
        a[1]=ui->get_y->text().toFloat();
    }
    else if(b==2){
        a[0]=ui->wait_x->text().toFloat();
        a[1]=ui->wait_y->text().toFloat();
    }
    else if(b==3){
        a[0]=ui->put_x->text().toFloat();
        a[1]=ui->put_y->text().toFloat();
    }

    QString coordinateString=QString("zuobiao/%1/%2/%3").arg(b).arg(a[0]).arg(a[1]);

    QByteArray coordinateByte=coordinateString.toUtf8();

    tcpSocket->write(coordinateByte);

}


void Widget::on_wait_clicked()
{

}

void Widget::on_restart_clicked()
{
//    thread=new MyThread(this);
//    thread->start();
}
