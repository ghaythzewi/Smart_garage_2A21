#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "facture.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_ajouter_button_clicked();

   // void on_le_reference_cursorPositionChanged(int arg1, int arg2);


    void stats(QString,QString,int,int,QString);


    void on_statsmontant_clicked();

    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_8_clicked();

    void on_lineEdit_9_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Facture F;
};

#endif // MAINWINDOW_H
