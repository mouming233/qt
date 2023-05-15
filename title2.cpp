#include "title2.h"
#include "ui_title2.h"
#include <QDebug>
#include <QMouseEvent>
title2::title2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::title2)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked(bool)),this, SLOT(onClicked()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this, SLOT(onClicked()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this, SLOT(onClicked()));
}

title2::~title2()
{
    delete ui;
}


void title2::mousePressEvent(QMouseEvent *event){
    //鼠标左键按下事件
    if(event->button()==Qt::LeftButton)
    {
        //记录鼠标左键状态
        m_leftButtonPressed = true;
        //记录鼠标在屏幕中的位置
        m_start = event->globalPos();
//        qDebug()<<QString::fromLocal8Bit("左键被按下了");
    }

}

void title2::mouseMoveEvent(QMouseEvent *event){
    if(m_leftButtonPressed)
        {
            //将父窗体移动到父窗体原来的位置加上鼠标移动的位置:event->globalPos()-m_start
            //this->window（）获取
            this->window()->move(this->window()->geometry().topLeft()+event->globalPos()-m_start);
            //将鼠标在屏幕中的位置替换为新的位置
            m_start = event->globalPos();
        }

}
void title2::setLable(const QString &text){
    ui->label->setText(text);
}

void title2::mouseReleaseEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton)
    {
        m_leftButtonPressed = false;
    }
}
void title2::on_pushButton_3_clicked(){

}

void title2::seticon(const QString &line){
    QIcon icon(line);
    ui->pushButton_3->setIcon(icon);
}

void title2::onClicked(){
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
       QWidget *pWindow = this->window();

       if (pWindow->isTopLevel())
       {
           if(pButton == ui->pushButton)
           {
               pWindow->showMinimized();
           }
           else if(pButton == ui->pushButton_2)
           {
               pWindow->close();
           }

       }


}
