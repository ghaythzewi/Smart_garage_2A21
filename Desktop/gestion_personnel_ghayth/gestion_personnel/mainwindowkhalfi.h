#ifndef MAINWINDOWKHALFI_H
#define MAINWINDOWKHALFI_H

#include <QMainWindow>
#include "personnel.h"
namespace Ui {
class MainWindowkhalfi;
}

class MainWindowkhalfi : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowkhalfi(QWidget *parent = nullptr);
    ~MainWindowkhalfi();
private slots:
    void on_pb_ajouter_clicked();


   void on_pb_supprimer_clicked();

   void on_pushButton_9_clicked();



   void on_trinom_toggled(bool checked);

   void on_tricin_toggled(bool checked);

   void on_recherche_pb_clicked();

   void on_pb_pdf_clicked();

   void on_pb_statistique_clicked();

 //  void on_pushButton_ajoutPerssonel_clicked();

  // void on_pushButton_3_clicked();

//   void on_pushButton_precedent_Candidat_clicked();

private:
    personnel P;
};

#endif // MAINWINDOWKHALFI_H
