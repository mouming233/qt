#include "title.h"
#include "ui_title.h"
#include"QVBoxLayout"

title::title(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::title)
{

    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    t2=new title2(this);
    t2->setParent(this);
    t2->setLable("中央调度系统");
    t2->seticon("://tb.ico");
    QVBoxLayout* layout = new QVBoxLayout(this);
   layout->addWidget(t2);
//   layout->addWidget(ui->widget);

   //设置垂直布局间隙
   layout->setSpacing(0);
   layout->setMargin(0);
}

title::~title()
{
    delete ui;
}


void title::paintEvent(QPaintEvent * ev)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap("://zhuye.jpg"),QRect());
}

void title::on_pushButton_clicked()
{
    zhong*gui1=new zhong;

    gui1->show();

    this->hide();
}
