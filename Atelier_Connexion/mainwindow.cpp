#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "facture.h"
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <QQuickItem>
#include <QSqlQueryModel>
#include <QPlainTextEdit>
#include <QDateTime>
//Include Stats
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QSqlQueryModel>
QT_CHARTS_USE_NAMESPACE
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->facture_affiche->setModel(F.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_button_clicked()
{ QString client=ui->le_id_client->text();
int reference=ui->le_reference->text().toInt();//
 float montant=ui->le_montant->text().toFloat();

 QString caissier=ui->le_caissier->text();
 QString achats=ui->lineEdit_6->text();
 QString date=ui->date_time->text();

  Facture F(reference,client,montant,caissier,date,achats);
bool test=F.ajouter();
if(test)
{

    QMessageBox::information(nullptr,QObject::tr("OK"),
    QObject::tr("Ajout effectué\n"
    "click Cancel to exit"),QMessageBox::Cancel);
     ui->facture_affiche->setModel(F.afficher());//Refresh
}
else
    QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
    QObject::tr("Ajout not effectué.\n"
    "Click Cancel to exit"), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()

{
  Facture F;
  F.setreference(ui->le_reference->text().toInt());
  bool test=F.supprimer(F.getrefernce());

  if(test)
  {

      QMessageBox::information(nullptr,QObject::tr("OK"),
      QObject::tr("Suppression avec succes.\n"
      "click Cancel to exit"),QMessageBox::Cancel);
      ui->facture_affiche->setModel(F.afficher());
  }
  else
      QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
      QObject::tr("Echec de suppression.\n"
      "Click Cancel to exit"), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{

    int reference=ui->le_reference->text().toInt();//
     float montant=ui->le_montant->text().toFloat();
     QString client=ui->le_id_client->text();
     QString caissier=ui->le_caissier->text();
     QString achats=ui->lineEdit_6->text();
     QString date;



    Facture F;
           bool test;
           test=F.modifier(reference,client,montant,caissier,date,achats);
           if(test)
           {
              ui->facture_affiche->setModel(F.afficher());

              QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr(" stade modifé") ,QMessageBox::Ok);

             }else

                 QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                   QObject::tr("Erreur !.\n""Click Ok to exit."), QMessageBox::Ok);
    }
void MainWindow::stats(QString table,QString critere,int valeur1,int valeur2,QString unite)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString valeur1QString=QString::number(valeur1);
    QString valeur2QString=QString::number(valeur2);

                model->setQuery("select * from "+table+" where "+critere+"<"+valeur1QString);

                float countFirst=model->rowCount();
                model->setQuery("select * from "+table+" where " +critere+" between " +valeur1QString+ " and "+valeur2QString);
                float countSecond=model->rowCount();
                model->setQuery("select * from "+table+" where " +critere+">"+valeur2QString);
                float countThird=model->rowCount();
                float total=countFirst+countSecond+countThird;
                QString a=QString("moins de "+valeur1QString+" "+unite+" "+QString::number((countFirst*100)/total,'f',2)+"%" );

                QString b=QString("entre "+valeur1QString+ " et " +valeur2QString+" "+unite+" "+QString::number((countSecond*100)/total,'f',2)+"%" );
                QString c=QString("Plus que "+valeur2QString +" "+unite+" "+QString::number((countThird*100)/total,'f',2)+"%" );
                QPieSeries *series = new QPieSeries();
                series->append(a,countFirst);
                series->append(b,countSecond);
                series->append(c,countThird);
        if (countFirst!=0)
        {QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());}
        if ( countSecond!=0)
        {
                 // Add label, explode and define brush for 2nd slice
                 QPieSlice *slice1 = series->slices().at(1);
                 //slice1->setExploded();
                 slice1->setLabelVisible();
        }
       if(countThird!=0)
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
                if(critere=="Montant")
                    critere="montant";
                chart->setTitle("Pourcentage Par " +critere+":Nombre Des " +table+" :" +QString::number(total));
                chart->legend()->hide();
                // Used to display the chart
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);
                chartView->show();
}


void MainWindow::on_statsmontant_clicked()
{
    stats("FACTURE","MONTANT",10,1000,"DT");
}



void MainWindow::on_pushButton_8_clicked() //imprimer
{

}






void MainWindow::on_lineEdit_9_textChanged(const QString &arg1) //recherche
{
    Facture c;
            if(ui->lineEdit_9->text() == "")
                {
                    ui->facture_affiche_2->setModel(c.afficher());
                }
                else
                {
                     ui->facture_affiche_2->setModel(c.rechercher(ui->lineEdit_9->text()));
                }
}
