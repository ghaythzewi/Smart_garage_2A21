#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include "clients.h"
namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

private slots:
    void on_pushButton_12_clicked();

    void on_pb_ajouter_clicked();

private:
    Ui::client *ui;
};

#endif // CLIENT_H
