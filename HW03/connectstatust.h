#ifndef CONNECTSTATUST_H
#define CONNECTSTATUST_H

#include <QDialog>

namespace Ui {
class ConnectStatust;
}

class ConnectStatust : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectStatust(QWidget *parent = nullptr);
    ~ConnectStatust();
    void setData(const QString& data, bool status);

private:
    Ui::ConnectStatust *ui;
};

#endif // CONNECTSTATUST_H
