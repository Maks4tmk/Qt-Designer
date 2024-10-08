#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(450, 220);
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::on_pb_ok_clicked()
{
    QStatusBar * StatusBar = statusBar();
    StatusBar->showMessage("Подключение...", 1000);

    db.setHostName(ui->le_hostName->text());
    db.setDatabaseName(ui->le_bdName->text());
    db.setUserName(ui->le_login->text());
    db.setPassword(ui->le_password->text());
    db.setPort(ui->sb_port->value());

    connected = db.open();
    qDebug() << "BD conect:" << connected;

    QString connectionInfo = "Host name: " + ui->le_hostName->text() + "\n";
    connectionInfo.append("Data base: " + ui->le_bdName->text()   + "\n");
    connectionInfo.append("Login: "     + ui->le_login->text()    + "\n");
    connectionInfo.append("Password: "  + ui->le_password->text() + "\n");
    connectionInfo.append("Port: "      + ui->sb_port->text()     + "\n");

    connStatus->show();
    connStatus->setData(connectionInfo, connected);

}

