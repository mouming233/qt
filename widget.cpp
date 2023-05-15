#include "widget.h"
#include "ui_widget.h"
#include"QVBoxLayout"

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


//   connect()

//    connect()
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
//     emit ChangeUISLot();
}
