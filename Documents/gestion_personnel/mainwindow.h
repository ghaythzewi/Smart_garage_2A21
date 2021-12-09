#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMainWindow>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QRegularExpression>
#include <QTableWidgetItem>
#include <QItemSelectionModel>
#include <QDebug>
#include <QSqlTableModel>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <qtextbrowser.h>



#include <QPropertyAnimation>
#include <QSound>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QInputDialog>
#include "client.h"
#include "personnel.h"
#include"excel.h"
#include "historique.h"
#include "arduino.h"
#include "smtp.h"
//#include "stats.h"
//#include "arduino.h"
#include "personnel.h"
#include "client.h"

#include "voiture.h"


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
    void on_pb_ajouter12_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_tri_parprenom_clicked();

    void on_tri_parnom_clicked();

    void on_tri_parcin_clicked();

    void on_pushButton_send_email_clicked();

    void on_pushButton_browse_email_clicked();

    void mailSent(QString);

    void on_cin_recherche_2_textChanged(const QString &arg1);

    void on_pushButton_stat_clicked();


    //khalfi
    void on_pb_ajouter_clicked();


   void on_pb_supprimer_12_clicked();

   void on_pushButton_9_clicked();



   void on_trinom_toggled(bool checked);

   void on_tricin_toggled(bool checked);

   void on_recherche_pb_clicked();

   void on_pb_pdf_clicked();

   void on_pb_statistique_clicked();

 //  void on_pushButton_ajoutPerssonel_clicked();

  // void on_pushButton_3_clicked();

//   void on_pushButton_precedent_Candidat_clicked();


   //ghayth
   void on_pb_ajouter_2_clicked();

   void on_pb_sup_22_clicked();

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


   void on_ahmed_clicked();

   void on_khalfi_clicked();

   void on_ghayth_clicked();

   void on_pushButton_2_clicked();




   void on_pb_supprimer_2_clicked();

private:
    Ui::MainWindow *ui;
    personnel P;
     Client c ;
        QStringList files;
        QByteArray data; // variable contenant les données reçues //arduino
            Arduino A; // objet temporaire
            Voiture v ;
            Voiture Voit;
};

#endif // MAINWINDOW_H
