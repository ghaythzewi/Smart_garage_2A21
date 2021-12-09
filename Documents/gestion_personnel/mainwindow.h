#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/////wael/////
#include <QMainWindow>
#include "personnel.h"

/////ghayth/////
#include "arduino.h"
#include <QMainWindow>
#include "voiture.h"

/////Ahmed/////
#include <QDialog>
#include<QSqlDatabase>
#include<clients.h>
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
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    //////wael
    void on_wael_clicked();

    void on_return_2_clicked();

    void on_pb_ajouter_clicked();

   void on_pb_supprimer_clicked();

   void on_pushButton_9_clicked();

   void on_trinom_toggled(bool checked);

   void on_tricin_toggled(bool checked);

   void on_recherche_pb_clicked();

   void on_pb_pdf_clicked();

   void on_pb_statistique_clicked();
   //////ghayth
    void on_Ghayth_clicked();

   void on_return_3_clicked();

   void on_pb_ajouter_2_clicked();

   void on_pb_sup_clicked();

   void on_pb_modifer_clicked();

   void on_combo_currentIndexChanged(const QString &arg1);

   void on_gadour_currentTextChanged(const QString &arg1);

       void on_pb_archv_clicked();

       void on_restaurer_clicked();

       void on_tabzarch_activated(const QModelIndex &index);

       void on_tabvoit_activated(const QModelIndex &index);

       void on_sup_arch_clicked();

       void on_sup1_arch_clicked();

       void on_trimarque_clicked();

       void update_label();
       // ce slot est lancé à chaque réception d'un message de Arduino

       void on_defaut_clicked();

       void on_pb_affecter_clicked();

       void on_pb_archv_2_clicked();
           //////ahmed
       void on_Ahmed_clicked();

       void on_return_4_clicked();
       void on_pb_ajouter12_clicked();

       void on_pushButton_3_clicked();

       void on_pushButton_stat_clicked();

       void on_pb_supprimer_2_clicked();



       void on_pushButton_2_clicked();

       void on_comboBox_activated(const QString &arg1);

       void on_tri_parnom_clicked();

       void on_tri_parcin_clicked();

       void on_tri_parprenom_clicked();

       void on_pushButton_send_email_clicked();

       void on_pushButton_browse_email_clicked();

       void mailSent(QString status);

       void on_cin_recherche_2_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    //////wael
    personnel P;
    //////ghayth
    QByteArray data; // variable contenant les données reçues //arduino
    Arduino A; // objet temporair
    Voiture v ;
    Voiture Voit;
    //////ahmed
    Clients c ;
    QStringList files;
};

#endif // MAINWINDOW_H
