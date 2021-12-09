#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H

#include <QDialog>
#include <QSqlDatabase>
#include <clients.h>



namespace Ui {
class gestionclient;
}

class gestionclient : public QDialog
{
    Q_OBJECT

public:
    explicit gestionclient(QWidget *parent = nullptr);
    ~gestionclient();


private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimerr_clicked();

    void on_pb_modifier_clicked();


private:
    Ui::gestionclient *ui;
    clients cl,c1 ;
};

#endif // GESTIONCLIENT_H
