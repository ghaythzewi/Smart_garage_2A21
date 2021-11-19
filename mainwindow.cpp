#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<stock.h>
#include<qmessagebox.h>
#include<dialog.h>
#include "historique.h"
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

    Historique h;
      h.save("nom :"+ui->le_nom->text(),"marque :"+ui->le_marque->text(),"fournisseur:"+ui->le_fournisseur->text());

    if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("Ajouter stock"),
                        QObject::tr("stock Ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter stock"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_4_clicked() //supprimer
{
    Stock s;
    QString nom=ui->nom_del->text();
    QString marque=ui->marque_del->text();
    s.setnom(nom);
    s.setmarque(marque);
    bool test=s.supprimer();
    if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("supprimer stock"),
                        QObject::tr("stock supprimer.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("supprimer stock"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
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
    if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("modifier stock"),
                        QObject::tr("stock modifié.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("modifier stock"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}
void MainWindow::on_chercher_clicked()
{
    /*Stock B;
    int numserie = ui->lineEdit_rech->text().toInt();

    QSqlQueryModel * model=B.recherche(numserie);
    //ui->tablerech->setModel(B.afficher());
    ui->tablerech->setModel(model);
*/
    QString rech = ui->lineEdit_rech->text();

      Stock s;
       QSqlQueryModel * model=s.recherche(rech);
       ui->tablerech->setModel(model);

}



/*

void MainWindow::on_localiser_clicked()
{
   Qstring numserie = ui->lineEdit_rech->text();
}
*/

void MainWindow::on_pb_stat_clicked()
{   Dialog *dialog;
    dialog=new Dialog(this);
    dialog->show();
}


void MainWindow::on_pushButton_8_clicked()
{
    QString link="C:/Users/MSI/Desktop/QT/histo.txt";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_pushButton_clicked()
{
      Stock s;
        if(ui->radioButton_trier_Stock_AZ->isChecked()){
        QString type=ui->comboBox_tri_Stock->currentText();
            ui->tablerech->setModel(s.afficher_trier(type,"ASC"));}

        if(ui->radioButton_trier_Stock_ZA->isChecked()){
            QString type=ui->comboBox_tri_Stock->currentText();
                ui->tablerech->setModel(s.afficher_trier(type,"DESC"));}
}

void MainWindow::on_pushButton_2_clicked()
{

       Stock s;
        bool test=s.EXCEL();


        QMessageBox msgBox;
            if(test)
            {
                msgBox.setText("Export avec succes.");
                ui->tablestock->setModel(s.afficher());
            }
            else
                msgBox.setText("Echec d'export.");
            msgBox.exec();

}
