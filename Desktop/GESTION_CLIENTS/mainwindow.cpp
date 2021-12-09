#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDialog"
#include "connection.h"
#include "QDialog"
#include "QTabWidget"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)  :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_supprimerr_clicked()
{

}
