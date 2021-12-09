#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H
#include <QDialog>
#include<QSqlDatabase>
#include<client.h>
#include <QMainWindow>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlRecord>
#include <QDateEdit>
#include <QDialog>
#include <QFileDialog>
#include <QSortFilterProxyModel>
#include <QSslConfiguration>

namespace Ui {
class gestionclient;
}

class gestionclient : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_pb_ajouter12_clicked();





  //  void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_activated(const QString &arg1);

    //void on_pb_recherche_clicked();

    void on_pb_supprimer_clicked();

    void on_tri_parprenom_clicked();

    void on_tri_parnom_clicked();

    void on_tri_parcin_clicked();



 //   void on_cin_recherche_2_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();

    void on_pushButton_send_email_clicked();

    void on_pushButton_browse_email_clicked();

    void mailSent(QString);

    void on_cin_recherche_2_textChanged(const QString &arg1);

    void on_pushButton_stat_clicked();

public:
    explicit gestionclient(QWidget *parent = nullptr);
    ~gestionclient();

private:

    Client c;
        QStringList files;

};

#endif // GESTIONCLIENT_H
