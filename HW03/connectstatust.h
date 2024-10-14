#ifndef CONNECTSTATUST_H
#define CONNECTSTATUST_H

#include <QDialog>
#include <QSqlDatabase>


namespace Ui {
class ConnectStatust;
}

class ConnectStatust : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectStatust(QWidget *parent = nullptr);
    ~ConnectStatust();
    void getData(QString& data);
    void disconnect();

signals:
    void update_info();

private slots:
    void on_pb_OK_clicked();


private:
    Ui::ConnectStatust *ui;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    bool connected;
};

#endif // CONNECTSTATUST_H
