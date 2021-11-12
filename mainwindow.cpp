#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<stock.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    QString nom=ui->le_nom->text();
    QString marque=ui->le_marque->text();
    QString fournisseur=ui->le_fournisseur->text();
    int quantite=ui->le_quantite->text().toInt();
    int prix=ui->le_prix->text().toInt();
    int numserie=ui->le_numserie->text().toInt();
    QString dateimport=ui->le_dateimport->text();
    Stock s(nom,marque,prix,dateimport,fournisseur,quantite,numserie);
    bool test=s.Ajouter();

}

void MainWindow::on_pushButton_4_clicked()
{
    Stock s;
    QString nom=ui->nom_del->text();
    QString marque=ui->marque_del->text();
    s.setnom(nom);
    s.setmarque(marque);
    bool test=s.supprimer();
}

void MainWindow::on_pb_afficher_clicked()
{
    Stock A;
   ui->tablestock->setModel(A.afficher());
}

void MainWindow::on_pushButton_6_clicked()//modifier
{
    QString fournisseur=ui->fournisseur_edit->text();
    int quantite=ui->quantite_edit->text().toInt();
    int prix=ui->prix_edit->text().toInt();
    int numserie=ui->numserie_edit->text().toInt();
    QString dateimport=ui->le_dateimport->text();
    Stock s("","",prix,dateimport,fournisseur,quantite,numserie);

    bool test=s.modifier();

}
