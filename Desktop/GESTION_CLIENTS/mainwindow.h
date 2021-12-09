#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gestionclient.h"
#include "clients.h"
#include <QMainWindow>
#include <QObject>


namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_le_adresse_cursorPositionChanged(int arg1, int arg2);

    void on_pb_supprimerr_clicked();

private:
    Ui::MainWindow *ui;
    clients cl ;

};
#endif // MAINWINDOW_H
