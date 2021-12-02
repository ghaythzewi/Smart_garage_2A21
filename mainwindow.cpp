#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "voiture.h"
#include<QString>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QMessageBox>
#include<QSqlQueryModel>
#include <QTableWidget>
#include <QIntValidator>


#include<QtCharts>
#include<QChartView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    ui->gadour->addItem("MITSUBISHI");
    ui->gadour->addItem("OPEL");
    ui->gadour->addItem("AUDI");
    ui->gadour->addItem("MERCEDES BENZ");
    ui->gadour->addItem("PEUGEOT");
    ui->gadour->addItem("FIAT");
    ui->gadour->addItem("BMW");

    ui->panne->addItem("MOTEUR");
    ui->panne->addItem("PARE-BRISE");
    ui->panne->addItem("PNEUS");
    ui->panne->addItem("LAVAGE");
    ui->panne->addItem("CIRCUIT ELECTRIQUE");
    ui->panne->addItem("DIESEL");


ui->combo->setModel(Voit.getcins());
    ui->tabvoit->setModel(v.afficher());
    ui->tabzarch->setModel(v.archive());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{bool test=false;
    int a=v.row_count();
    if(a<15)
    {QSqlQuery query;
    QString matricule=ui->matric->text();
    QString marque=ui->gadour->currentText();
    QString cin_prop=ui->combo->currentText();
    int nb_visites=ui->nbv->text().toInt();
QString modele=ui->iyadh->currentText();
QString panne=ui->panne->currentText();
QString affectation="NON AFFECTEE";
 Voiture V(matricule,marque,nb_visites,cin_prop,modele,panne,affectation);
    test= V.ajouter();

    if(test)
    {ui->tabvoit->setModel(V.afficher());
        ui->tabzarch->setModel(v.archive());
        ui->matric->clear();
        ui->nbv->clear();

        QMessageBox::information(nullptr, QObject::tr("AJOUT"),
                    QObject::tr("AJOUT AVEC SUCCES.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
    { ui->matric->clear();
        ui->nbv->clear();

        QMessageBox::critical(nullptr, QObject::tr("AJOUT"),
                    QObject::tr("ERREUR.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}}
    else
    {QMessageBox::critical(nullptr, QObject::tr("NOTIFICATION"),   //METIER NOTIFICATION
                           QObject::tr("GARAGE SATURE : MAX 5.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel); }




}

void MainWindow::on_pb_sup_clicked()
{Voiture v1;
bool test=false;

QSqlQuery query;


     v1.setmatricule(ui->matric_2->text());
     test= v1.supprimer(v1.getmatricule());


    if(test)
    {ui->tabvoit->setModel(v1.afficher());
        ui->tabzarch->setModel(v1.archive());
        ui->b->clear();
        ui->c->clear();
        ui->d->clear();
        ui->e->clear();
        ui->f->clear();
        ui->matric_2->clear();
        QMessageBox::information(nullptr, QObject::tr("sup"),
                    QObject::tr("suppression effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("sup"),
                    QObject::tr("erreur suppression.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

}

void MainWindow::on_pb_modifer_clicked()
{
    bool test=false;
     QSqlQuery query;
        QString matricule=ui->matric->text();
        QString marque=ui->gadour->currentText();
        QString cin_prop=ui->combo->currentText();
        int nb_visites=ui->nbv->text().toInt();
       QString modele=ui->iyadh->currentText();
        QString panne=ui->panne->currentText();
        QString affectation="NON AFFECTEE";
         Voiture V(matricule,marque,nb_visites,cin_prop,modele,panne,affectation);

         V.setmatricule(ui->matric->text());
          test=V.modifier(V.getmatricule());

        if(test)
        {ui->tabvoit->setModel(V.afficher());

            ui->matric->clear();
           ui->nbv->clear();
            ui->panne->clear();

            QMessageBox::information(nullptr, QObject::tr("MODIFICATION"),
                        QObject::tr("Modification effectuée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
        {ui->matric->clear();

            ui->nbv->clear();

            ui->panne->clear();
            QMessageBox::critical(nullptr, QObject::tr("MODIFICATION"),
                        QObject::tr("Erreur lors de la modification.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}


}



void MainWindow::on_combo_currentIndexChanged(const QString &arg1)
{
     Voit.getcin2((&arg1)->toInt());
}

void MainWindow::on_gadour_currentTextChanged(const QString &arg1)
{if(arg1=="OPEL")
    {ui->iyadh->clear();
        ui->iyadh->addItem("ASTRA");
        ui->iyadh->addItem("CORSA");
        ui->iyadh->addItem("AGILA");
        ui->iyadh->addItem("SENATOR");
        ui->iyadh->addItem("ARENA");

    }
    else if (arg1 == "MITSUBISHI") {
            ui->iyadh->clear();
            ui->iyadh->addItem("CANTER");
            ui->iyadh->addItem("ASX");
            ui->iyadh->addItem("CARISMA");
            ui->iyadh->addItem("LANCER");
            ui->iyadh->addItem("PAJERO");
        }
    else if (arg1 == "MERCEDES BENZ") {
            ui->iyadh->clear();
            ui->iyadh->addItem("AMG");
            ui->iyadh->addItem("GLA");
            ui->iyadh->addItem("GLC");
            ui->iyadh->addItem("G");
            ui->iyadh->addItem("S");
        }
    else if (arg1 == "BMW") {
            ui->iyadh->clear();
            ui->iyadh->addItem("X5");
            ui->iyadh->addItem("SERIE1");
            ui->iyadh->addItem("M5");
            ui->iyadh->addItem("M4");
            ui->iyadh->addItem("Z6");
        }
    else if (arg1 == "FIAT") {
            ui->iyadh->clear();
            ui->iyadh->addItem("PALIO");
            ui->iyadh->addItem("PUNTO");
            ui->iyadh->addItem("UNO");
            ui->iyadh->addItem("GRANDI");
            ui->iyadh->addItem("F500");
        }
    else if (arg1 == "AUDI") {
            ui->iyadh->clear();
            ui->iyadh->addItem("A4");
            ui->iyadh->addItem("RS3");
            ui->iyadh->addItem("E-TRON");
            ui->iyadh->addItem("TT");
            ui->iyadh->addItem("Q3");
        }
    else if (arg1 == "PEUGEOT") {
            ui->iyadh->clear();
            ui->iyadh->addItem("206");
            ui->iyadh->addItem("307");
            ui->iyadh->addItem("407");
            ui->iyadh->addItem("2008");
            ui->iyadh->addItem("508");
        }

}

void MainWindow::on_pb_archv_clicked()
{bool test,test2;
    QString matricule=ui->matric_2->text();
    QString marque=ui->c->text();
    QString cin_prop=ui->d->text();
    int nb_visites=ui->b->text().toInt();
    QString modele=ui->f->text();
    QString panne=ui->e->text();
    QString affectation="NON AFFECTEE";
     Voiture V(matricule,marque,nb_visites,cin_prop,modele,panne,affectation);
      test=V.ajouter_archive();
      test2=V.supprimer(matricule);


      if(test&&test2)
      {ui->tabvoit->setModel(V.afficher());
          ui->tabzarch->setModel(v.archive());
          ui->b->clear();
          ui->c->clear();
          ui->d->clear();
          ui->e->clear();
          ui->f->clear();
          ui->matric_2->clear();
          QMessageBox::information(nullptr, QObject::tr("Historique"),
                      QObject::tr("Archivage effectué.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


  }
      else
      {
          QMessageBox::critical(nullptr, QObject::tr("Historique"),
                      QObject::tr("erreur Archivage.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);}

}

void MainWindow::on_restaurer_clicked() //restauration de zarch vers gvoit
{
    bool test,test2;
        QString matricule=ui->mat->text();
        QString marque=ui->mar->text();
        QString cin_prop=ui->cin->text();
        int nb_visites=ui->vis->text().toInt();
        QString modele=ui->mod->text();
        QString panne=ui->pan->text();
        QString affectation="NON AFFECTEE";
         Voiture V(matricule,marque,nb_visites,cin_prop,modele,panne,affectation);
          test=V.ajouter();
          test2=V.supprimer_archive(matricule);


          if(test&&test2)
          {ui->tabvoit->setModel(V.afficher());
              ui->tabzarch->setModel(v.archive());
              ui->mat->clear();
              ui->mar->clear();
              ui->mod->clear();
              ui->pan->clear();
              ui->vis->clear();
              ui->cin->clear();
              QMessageBox::information(nullptr, QObject::tr("Historique"),
                          QObject::tr("Archivage effectué.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);


      }
          else
          {
              QMessageBox::critical(nullptr, QObject::tr("Historique"),
                          QObject::tr("erreur Archivage.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_tabzarch_activated(const QModelIndex &index)
{ QString val=ui->tabzarch->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM ZARCHIVE WHERE MATRICULE='"+val+"'  ");

    if(query.exec())
    {while(query.next())
        {ui->mat->setText(query.value(0).toString());

ui->vis->setText(query.value(1).toString());
ui->mod->setText(query.value(2).toString());
ui->cin->setText(query.value(3).toString());
ui->pan->setText(query.value(4).toString());
ui->mar->setText(query.value(5).toString());
        }



    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("sup"),
                    QObject::tr("ERREUR .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

}

void MainWindow::on_tabvoit_activated(const QModelIndex &index)
{
    QString val=ui->tabvoit->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT * FROM GVOITURE WHERE MATRICULE='"+val+"'  ");

        if(query.exec())
        {while(query.next())
            {
    ui->matric_2->setText(query.value(0).toString());
    ui->b->setText(query.value(1).toString());
    ui->c->setText(query.value(2).toString());
    ui->d->setText(query.value(3).toString());
    ui->e->setText(query.value(4).toString());
    ui->f->setText(query.value(5).toString());
            }



        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ARCHIVE"),
                        QObject::tr("ERREUR .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}

}



void MainWindow::on_sup_arch_clicked() //vider(all columns)
{Voiture v1;
    bool test=false;

      QSqlQuery query;

      test=v1.vider_archive();

        if(test)
        {ui->tabvoit->setModel(v1.afficher());
            ui->tabzarch->setModel(v1.archive());
            ui->mat->clear();
            ui->mar->clear();
            ui->mod->clear();
            ui->pan->clear();
            ui->vis->clear();
            ui->cin->clear();
            QMessageBox::information(nullptr, QObject::tr("ARCHIVE"),
                        QObject::tr("ARCHIVE VIDE.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("sup"),
                        QObject::tr("ERREUR.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}

}

void MainWindow::on_sup1_arch_clicked() //kaaba bark
{
    Voiture v1;
    bool test=false;

    QSqlQuery query;

         v1.setmatricule(ui->mat->text());
         test= v1.supprimer_archive(v1.getmatricule());

        if(test)
        {ui->tabvoit->setModel(v1.afficher());
            ui->tabzarch->setModel(v1.archive());
            ui->mat->clear();
            ui->mar->clear();
            ui->mod->clear();
            ui->pan->clear();
            ui->vis->clear();
            ui->cin->clear();
            QMessageBox::information(nullptr, QObject::tr("sup"),
                        QObject::tr("suppression effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
   }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("sup"),
                        QObject::tr("erreur suppression.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}

}



void MainWindow::on_trimarque_clicked()
{
    ui->tabvoit->setModel(v.AfficherTrimarque());

}



void MainWindow::on_defaut_clicked()
{
    ui->tabvoit->setModel(v.afficher());
}

void MainWindow::on_pb_affecter_clicked()
{bool test,test2;
    QString ch=ui->e->text();
    if(ch=="MOTEUR")
    {QString val="motoriste";
        QSqlQuery query;
        query.prepare("SELECT CINEMP,NOMEMP,PRENOMEMP,ETAT FROM PERSONNEL WHERE SPECIALITE='"+val+"'  ");

        if(query.exec())
        {if(query.next())//staff existe
     {ui->cinemp->setText(query.value(0).toString()) ;
    ui->nomemp->setText(query.value(1).toString());
    ui->prenomemp->setText(query.value(2).toString());
    QString q=ui->nomemp->text();
    QString etat=query.value(3).toString();
    QString p=ui->matric_2->text();
    if(etat=="DISPONIBLE")
    {
    test=v.update_personnel(q);
    test2=v.update_affectation(p);

    if(test&&test2)
    {ui->tabvoit->setModel(v.afficher());
        QMessageBox::information(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("AFFECTATION EFFECTUEE.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("ERREUR.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("PAS DE STAFF DISPONIBLE POUR LE MOMENT.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

            else //staff n'existe pas
            {
                QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                            QObject::tr("PAS DE STAFF DISPONIBLE POUR LE MOMENT.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}



}


    }


    else if(ch=="PARE_BRISE")
    {QString val="POSEUR PARE-BRISE";
        QSqlQuery query;
        query.prepare("SELECT CINEMP,NOMEMP,PRENOMEMP,ETAT FROM PERSONNEL WHERE SPECIALITE='"+val+"'  ");

        if(query.exec())
        {if(query.next())//staff existe
     {ui->cinemp->setText(query.value(0).toString()) ;
    ui->nomemp->setText(query.value(1).toString());
    ui->prenomemp->setText(query.value(2).toString());
    QString q=ui->nomemp->text();
    QString etat=query.value(3).toString();
    QString p=ui->matric_2->text();
    if(etat=="DISPONIBLE")
    {
    test=v.update_personnel(q);
    test2=v.update_affectation(p);

    if(test&&test2)
    {ui->tabvoit->setModel(v.afficher());
        QMessageBox::information(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("AFFECTATION EFFECTUEE.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("ERREUR.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("PAS DE STAFF DISPONIBLE POUR LE MOMENT.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

            else //staff n'existe pas
            {
                QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                            QObject::tr("PAS DE STAFF DISPONIBLE POUR LE MOMENT.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}



}


    }
    else if(ch=="PNEUS")
    {QString val="MONTEUR PNEUMATIQUE";
        QSqlQuery query;
        query.prepare("SELECT CINEMP,NOMEMP,PRENOMEMP,ETAT FROM PERSONNEL WHERE SPECIALITE='"+val+"'  ");

        if(query.exec())
        {if(query.next())//staff existe
     {ui->cinemp->setText(query.value(0).toString()) ;
    ui->nomemp->setText(query.value(1).toString());
    ui->prenomemp->setText(query.value(2).toString());
    QString q=ui->nomemp->text();
    QString etat=query.value(3).toString();
    QString p=ui->matric_2->text();
    if(etat=="DISPONIBLE")
    {
    test=v.update_personnel(q);
    test2=v.update_affectation(p);

    if(test&&test2)
    {ui->tabvoit->setModel(v.afficher());
        QMessageBox::information(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("AFFECTATION EFFECTUEE.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("ERREUR.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("PAS DE STAFF DISPONIBLE POUR LE MOMENT.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

            else //staff n'existe pas
            {
                QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                            QObject::tr("PAS DE STAFF DISPONIBLE POUR LE MOMENT.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}



}


    }
            else if(ch=="LAVAGE")
    {QString val="LAVEUR";
        QSqlQuery query;
        query.prepare("SELECT CINEMP,NOMEMP,PRENOMEMP,ETAT FROM PERSONNEL WHERE SPECIALITE='"+val+"'  ");

        if(query.exec())
        {if(query.next())//staff existe
     {ui->cinemp->setText(query.value(0).toString()) ;
    ui->nomemp->setText(query.value(1).toString());
    ui->prenomemp->setText(query.value(2).toString());
    QString q=ui->nomemp->text();
    QString etat=query.value(3).toString();
    QString p=ui->matric_2->text();
    if(etat=="DISPONIBLE")
    {
    test=v.update_personnel(q);
    test2=v.update_affectation(p);

    if(test&&test2)
    {ui->tabvoit->setModel(v.afficher());
        QMessageBox::information(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("AFFECTATION EFFECTUEE.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("ERREUR.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("PAS DE STAFF DISPONIBLE POUR LE MOMENT.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

            else //staff n'existe pas
            {
                QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                            QObject::tr("PAS DE STAFF DISPONIBLE POUR LE MOMENT.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}



}


    }
    else if(ch=="CIRCUIT ELECTRIQUE")
    {QString val="ELECTRICIEN";
        QSqlQuery query;
        query.prepare("SELECT CINEMP,NOMEMP,PRENOMEMP,ETAT FROM PERSONNEL WHERE SPECIALITE='"+val+"'  ");

        if(query.exec())
        {if(query.next())//staff existe
     {ui->cinemp->setText(query.value(0).toString()) ;
    ui->nomemp->setText(query.value(1).toString());
    ui->prenomemp->setText(query.value(2).toString());
    QString q=ui->nomemp->text();
    QString etat=query.value(3).toString();
    QString p=ui->matric_2->text();
    if(etat=="DISPONIBLE")
    {
    test=v.update_personnel(q);
    test2=v.update_affectation(p);

    if(test&&test2)
    {ui->tabvoit->setModel(v.afficher());
        QMessageBox::information(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("AFFECTATION EFFECTUEE.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("ERREUR.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("PAS DE STAFF DISPONIBLE POUR LE MOMENT.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

            else //staff n'existe pas
            {
                QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                            QObject::tr("PAS DE STAFF DISPONIBLE POUR LE MOMENT.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}



}


    }
    else if(ch=="DIESEL")
    {QString val="DIESILISTE";
        QSqlQuery query;
        query.prepare("SELECT CINEMP,NOMEMP,PRENOMEMP,ETAT FROM PERSONNEL WHERE SPECIALITE='"+val+"'  ");

        if(query.exec())
        {if(query.next())//staff existe
     {ui->cinemp->setText(query.value(0).toString()) ;
    ui->nomemp->setText(query.value(1).toString());
    ui->prenomemp->setText(query.value(2).toString());
    QString q=ui->nomemp->text();
    QString etat=query.value(3).toString();
    QString p=ui->matric_2->text();
    if(etat=="DISPONIBLE")
    {
    test=v.update_personnel(q);
    test2=v.update_affectation(p);

    if(test&&test2)
    {ui->tabvoit->setModel(v.afficher());
        QMessageBox::information(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("AFFECTATION EFFECTUEE.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("ERREUR.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                    QObject::tr("PAS DE STAFF DISPONIBLE POUR LE MOMENT.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

            else //staff n'existe pas
            {
                QMessageBox::critical(nullptr, QObject::tr("AFFECTATION"),
                            QObject::tr("PAS DE STAFF DISPONIBLE POUR LE MOMENT.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}



}


    }


}

void MainWindow::on_pb_archv_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString val1="AUDI";
    QString val2="BMW";
    QString val3="OPEL";
                                model->setQuery("select * from GVOITURE where MARQUE='"+val1+"' ");
                                float nbr1=model->rowCount();
                                model->setQuery("select * from GVOITURE where MARQUE='"+val2+"' ");
                                float nbr2=model->rowCount();
                                model->setQuery("select * from GVOITURE where MARQUE='"+val3+"' ");
                                //count
                                float nbr3=model->rowCount();
                                float total=nbr1+nbr2+nbr3;
                                QString a=QString("AUDI "+QString::number((nbr1*100)/total,'f',2)+"%" );
                                QString b=QString("BMW "+QString::number((nbr2*100)/total,'f',2)+"%" );
                                QString c=QString("OPEL "+QString::number((nbr3*100)/total,'f',2)+"%" );
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
                                chart->setTitle("POURCENTAGE PAR NOMBRE DES VISITES "+ QString::number(total));
                                chart->legend()->hide();
                                // display the chart
                                QChartView *chartView = new QChartView(chart);
                                chartView->setRenderHint(QPainter::Antialiasing);
                                chartView->resize(1000,500);
                                chartView->show();

}

