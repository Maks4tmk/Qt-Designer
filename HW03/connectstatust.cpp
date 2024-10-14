#include "connectstatust.h"
#include "ui_connectstatust.h"

ConnectStatust::ConnectStatust(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConnectStatust)
{
    ui->setupUi(this);
    this->setFixedSize(450, 220);
    ui->le_hostname->setText("localhost");
    ui->sb_port->setValue(5432);
}

ConnectStatust::~ConnectStatust()
{
    delete ui;
}

void ConnectStatust::getData(QString& connectionInfo){

    QString connection("Failed");
    if (connected) connection = "Successful";
    else connection = "Failed";

    connectionInfo = "Host name: " + ui->le_hostname->text() + "\n";
    connectionInfo.append("Data base: " + ui->le_dbname->text()   + "\n");
    connectionInfo.append("Login: "     + ui->le_login->text()    + "\n");
    connectionInfo.append("Port: "      + ui->sb_port->text()     + "\n");
    connectionInfo.append("Connected: "  + connection);

}
void ConnectStatust::disconnect(){
    db.close();
}


void ConnectStatust::on_pb_OK_clicked()
{
    db.setHostName(ui->le_hostname->text());
    db.setDatabaseName(ui->le_dbname->text());
    db.setUserName(ui->le_login->text());
    db.setPassword(ui->le_password->text());
    db.setPort(ui->sb_port->value());

    connected = db.open();
    emit update_info();
    this->close();
}

