#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personnel.h"

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
    void on_pb_ajouter_clicked();


   void on_pb_supprimer_clicked();

   void on_pushButton_9_clicked();



   void on_trinom_toggled(bool checked);

   void on_tricin_toggled(bool checked);

   void on_recherche_pb_clicked();

   void on_pb_pdf_clicked();

   void on_pb_statistique_clicked();

private:
    Ui::MainWindow *ui;
    personnel P;

};

#endif // MAINWINDOW_H
