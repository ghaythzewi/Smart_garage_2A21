#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QSound>
#include <QtWidgets/QMessageBox>
#include <QFileDialog>
#include <QDialog>
#include <QtCharts>
#include <QWidget>
#include <QFrame>
#include <QMediaPlayer>
#include <QChartView>
#include <QPieSeries>
#include<QMessageBox>
#include<QTableView>
#include <QMainWindow>
#include <QtWidgets/QMessageBox>
#include<QTimer>

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

    void on_pushButton_4_clicked();

    void on_pb_afficher_clicked();

    void on_pushButton_6_clicked();
    void on_chercher_clicked();


    void on_tabWidget_3_currentChanged(int index);

    void on_pushButton_10_clicked();

    void on_localiser_clicked();

    void on_pb_stat_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
