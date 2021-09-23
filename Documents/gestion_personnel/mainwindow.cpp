#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "personnel.h"
#include "connection.h"
#include <QIntValidator>
#include <QDebug>
#include <QTableView>
#include <QSqlQuery>
#include <QString>
#include <QDate>
#include <QDateEdit>
#include <QRect>
#include<QtCharts>
#include<QChartView>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_cin->setValidator(new QIntValidator(0, 99999999, this));
    ui->l_CIN->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_cin_supp->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_tel->setValidator(new QIntValidator(0, 99999999, this));
    ui->l_tel->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_nbr_conge->setValidator(new QIntValidator(0, 99, this));
    ui->l_nbr_conge->setValidator(new QIntValidator(0, 99, this));
    ui->tab_personnel->QTableView:: setModel(P.afficher());
    setWindowIcon(QIcon(":/logo.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//-----------------ajout----------
void MainWindow::on_pb_ajouter_clicked()
{
    int cin=ui->le_cin-> text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString mail=ui->le_mail->text();
    QString adresse=ui->le_adresse->text();
    int tel=ui->le_tel->text().toInt();
    int nbr_conge=ui->le_nbr_conge->text().toInt();
    QString etat=ui->cb_ajouter->currentText();
    QString Specialite=ui->cb_genre->currentText();
    QDate date=ui->dateEdit->date();
    personnel P( cin , nom , prenom , mail, adresse , nbr_conge , tel , etat, Specialite,date);
    bool test=P.ajouter();
    ui->tab_personnel->QTableView:: setModel(P.afficher());
    QMessageBox msgBox;

      if(test)
       {
           msgBox.setText("AJOUT AVEC SUCCES.");
           msgBox.exec();
      }
        else
      {
          msgBox.setText("ECHEC DE L'AJOUT");
          msgBox.exec();
      }


}

//----------------supprimer------------

void MainWindow::on_pb_supprimer_clicked()
{
    personnel P1;
    P1.setcin(ui->le_cin_supp->text().toInt());
    bool test=P1.supprimer(P1.getcin());
    ui->tab_personnel->QTableView:: setModel(P.afficher());
    QMessageBox msgBox;

      if(test)
       {
           msgBox.setText("supprimer avec succes.");
           msgBox.exec();
      }
        else
      {
          msgBox.setText("echec de suppression");
          msgBox.exec();
      }

}
//---------------------modifier----------
void MainWindow::on_pushButton_9_clicked()
{
    ui->tab_personnel->QTableView::setModel(P.afficher());
    bool test=P.modifier(ui->l_CIN->text().toInt(),ui->l_nom->text(),ui->l_prenom->text(),ui->l_mail->text(),ui->l_adresse->text(),ui->l_tel->text().toInt(),ui->l_nbr_conge->text().toInt(),ui->cb_modifier->currentText(),ui->cb_genre_modifier->currentText(),ui->dateEdit->date());
    if (test)
              {
                      ui->tab_personnel->QTableView::setModel(P.afficher());

                  QMessageBox::information(nullptr,QObject::tr("OK"),
                                       QObject::tr("modification établie"),
                                       QMessageBox::Ok);}
              else{
              QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                      QObject::tr("modification non établie"),
                                      QMessageBox::Cancel);}
}

//-----------------tri
void MainWindow::on_trinom_toggled(bool checked)
{
    if (checked == true){
            ui->tab_personnel->QTableView::setModel(P.trierparnom());
        } else {
             ui->tab_personnel->QTableView::setModel(P.afficher());
        }
    }



void MainWindow::on_tricin_toggled(bool checked)
{
    if (checked == true){
            ui->tab_personnel->QTableView::setModel(P.trier());
        } else {
             ui->tab_personnel->QTableView::setModel(P.afficher());
        }
}
//----------------------recherche
void MainWindow::on_recherche_pb_clicked()
{
    QString nom = ui->lineEdit_chercher->text();
    ui->tab_personnel->QTableView::setModel(P.recherche(nom));
}
//------------------pdf
void MainWindow::on_pb_pdf_clicked()
{
    bool test=false;
       test=P.genererPDFproduit();
       if(test)

           {
           ui->tab_personnel->QTableView::setModel(P.afficher());
           QMessageBox::information(nullptr, QObject::tr("créé"),

                               QObject::tr(" PDF créé.\n"

                                           "Click Cancel to exit."), QMessageBox::Cancel);}
       else

           {

               QMessageBox::critical(nullptr, QObject::tr("non créé"),

                           QObject::tr("PDF non créé !.\n"

                                       "Click Cancel to exit."), QMessageBox::Cancel);



   }
}
//-------------------statistique
void MainWindow::on_pb_statistique_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                                model->setQuery("select * from PERSSONEL where NBR_CONGE < 7 ");
                                float nbr1=model->rowCount();
                                model->setQuery("select * from PERSSONEL where NBR_CONGE  between 2 and 5 ");
                                float nbr2=model->rowCount();
                                model->setQuery("select * from PERSSONEL where NBR_CONGE >3 ");
                                float nbr3=model->rowCount();
                                float total=nbr1+nbr2+nbr3;
                                QString a=QString(" nombre de congee inférieur  à 7 "+QString::number((nbr1*100)/total,'f',2)+"%" );
                                QString b=QString("nombre de congee entre 2 et 5 "+QString::number((nbr2*100)/total,'f',2)+"%" );
                                QString c=QString(" nombre de congee plus que 3 "+QString::number((nbr3*100)/total,'f',2)+"%" );
                                QPieSeries *series = new QPieSeries();
                                series->append(a,nbr1);
                                series->append(b,nbr2);
                                series->append(c,nbr3);
                        if (nbr1!=0)
                        {QPieSlice *slice = series->slices().at(0);
                         slice->setLabelVisible();
                         slice->setPen(QPen());}
                        if ( nbr2!=0)
                        {
                                 // Add label, explode and define brush for 2nd slice
                                 QPieSlice *slice1 = series->slices().at(1);
                                 //slice1->setExploded();
                                 slice1->setLabelVisible();
                        }
                        if(nbr3!=0)
                        {
                                 // Add labels to rest of slices
                                 QPieSlice *slice2 = series->slices().at(2);
                                 //slice1->setExploded();
                                 slice2->setLabelVisible();
                        }
                                // Create the chart widget
                                QChart *chart = new QChart();
                                // Add data to chart with title and hide legend
                                chart->addSeries(series);
                                chart->setTitle("Pourcentage Par nombre  :Nombre Des jeux "+ QString::number(total));
                                chart->legend()->hide();
                                // Used to display the chart
                                QChartView *chartView = new QChartView(chart);
                                chartView->setRenderHint(QPainter::Antialiasing);
                                chartView->resize(1000,500);
                                chartView->show();
}
