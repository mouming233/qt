#include "title2.h"
#include "ui_title2.h"

title2::title2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::title2)
{
    ui->setupUi(this);
}

title2::~title2()
{
    delete ui;
}
