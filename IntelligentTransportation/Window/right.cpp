#include "right.h"
#include "ui_right.h"

Right::Right(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Right)
{
    ui->setupUi(this);
}

Right::~Right()
{
    delete ui;
}
