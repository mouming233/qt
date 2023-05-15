#include "zhong.h"
#include "ui_zhong.h"

zhong::zhong(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zhong)
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

zhong::~zhong()
{
    delete ui;
}

void zhong::paintEvent(QPaintEvent * ev)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap("://background1.jpg"),QRect());
}

void zhong::on_pushButton_5_clicked()
{
    Widget *gui2=new Widget;
    gui2->show();
    this->hide();
}
