#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(450, 180);
    connect(connStatus, &ConnectStatust::update_info, this, &MainWindow::Update);
}


MainWindow::~MainWindow()
{
    connStatus->disconnect();
    delete ui;
}

void MainWindow::on_pb_ok_clicked()
{
    QString Info(" ");
    connStatus->show();
}



void MainWindow::Update(){
    QString Info(" ");
    connStatus->getData(Info);
    ui->le_info->setText(Info);
}
