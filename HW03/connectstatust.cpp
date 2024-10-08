#include "connectstatust.h"
#include "ui_connectstatust.h"

ConnectStatust::ConnectStatust(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConnectStatust)
{
    ui->setupUi(this);
    this->setFixedSize(450, 220);
}

ConnectStatust::~ConnectStatust()
{
    delete ui;
}

void ConnectStatust::setData(const QString& data, bool status){
    ui->te_info->setText(data);
    if (status){
        ui->la_status->setStyleSheet("color : green");
        ui->la_status->setText("Подключено!");
    }else{
        ui->la_status->setStyleSheet("color : red");
        ui->la_status->setText("Ошибка!!!");
    }
}


