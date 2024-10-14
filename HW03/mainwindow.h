#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QSqlDatabase>
#include "connectstatust.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ok_clicked();
    void Update();

private:
    Ui::MainWindow *ui;
    ConnectStatust* connStatus = new ConnectStatust(this);
    QString Info();
};
#endif // MAINWINDOW_H
