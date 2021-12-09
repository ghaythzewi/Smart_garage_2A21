#include "voiture.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include<QSqlQueryModel>
#include <QMessageBox>
#include <QObject>
Voiture::Voiture()
{matricule="";
    marque="";
    nb_visites=0;
    cin_prop="";

}

Voiture::Voiture(QString matricule,QString marque,int nb_visites,QString cin_prop,QString modele,QString panne,QString affectation)
{this->marque=marque;
    this->matricule=matricule;
    this->nb_visites=nb_visites;
    this->cin_prop=cin_prop;
    this->modele=modele;
    this->panne=panne;
    this->affectation=affectation;
}


QString Voiture::getmatricule()
{return matricule;}
QString Voiture::getmarque()
{return marque;}
int Voiture::getnbr()
{return nb_visites;}
QString Voiture::getcin()
{return cin_prop; }
void Voiture::setmatricule(QString ch1)
{matricule=ch1;}
void Voiture::setmarque(QString ch2)
{marque=ch2;}
void Voiture::setnbr(int x)
{nb_visites=x;}
void Voiture::setcin(QString y)
{cin_prop=y;}
QString Voiture::getpanne()
{return panne;}
QString Voiture::getaffect()
{return affectation;}
QString Voiture::getmodele()
{return modele;}
void Voiture::setpanne(QString ch3)
{panne=ch3;}
void Voiture::setmodele(QString ch4)
{modele=ch4;}
void Voiture::setaffect(QString ch5)
{affectation=ch5;}




bool Voiture::ajouter()
{

 QSqlQuery query;

QString nbr_visite_string=QString::number(nb_visites);
      query.prepare("INSERT INTO GVOITURE (MATRICULE,NBVISITES,MARQUE,CIN,PANNE,MODELE,AFFECTATION) "
                    "VALUES (:1, :4, :2, :3, :5, :6, :7)");

       query.bindValue(":1", matricule);
       query.bindValue(":4", nbr_visite_string);
       query.bindValue(":2", marque);
       query.bindValue(":3",cin_prop);
        query.bindValue(":5",panne);
         query.bindValue(":6",modele);
        query.bindValue(":7",affectation);
      return query.exec();


}

QSqlQueryModel * Voiture::afficher()
{
     QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM GVOITURE");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("VISITES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MARQUE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PANNE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MODELE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("AFFECTATION"));


    return model;
}



bool Voiture::supprimer(QString matricule)
{
    QSqlQuery query;

    query.prepare("Delete from GVOITURE where MATRICULE= :mat");

    query.bindValue(":mat",matricule);


    return query.exec();
}

bool Voiture :: modifier(QString matricule)

{
     QSqlQuery query;

    QString nbr_visite_string=QString::number(nb_visites);
        query.prepare("UPDATE GVOITURE SET MATRICULE=:MATRICULE ,NBVISITES=:NBVISITES,MARQUE=:MARQUE,CIN=:CIN, PANNE=:PANNE, MODELE=:MODELE WHERE MATRICULE=:mat");

        query.bindValue(":mat",matricule);

        query.bindValue(":MATRICULE", matricule);

        query.bindValue(":NBVISITES",nbr_visite_string);

        query.bindValue(":MARQUE", marque);

        query.bindValue(":CIN", cin_prop);

        query.bindValue(":PANNE", panne);

        query.bindValue(":MODELE", modele);

           return    query.exec();



}



QSqlQueryModel* Voiture::getcins()
{


    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT CIN FROM GESTIONCLIENT");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("CIN"));


    return model;
}


Voiture* Voiture::getcin2(int cin_prop)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM GESTIONCLIENT WHERE CIN = :CIN");
    query.bindValue(":CIN",cin_prop);
    query.exec();
    Voiture * c = new Voiture();
    while (query.next()) {
            c->setcin(query.value(0).toString()) ;

        }
    return c;
}


QSqlQueryModel * Voiture::archive()      //F1 Archive:affichage
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM ZARCHIVE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("VISITES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MARQUE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PANNE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MODELE"));

    return model;

}

bool Voiture::ajouter_archive()
{ QSqlQuery query;

    QString nbr_visite_string=QString::number(nb_visites);
        query.prepare("INSERT INTO ZARCHIVE (MATRICULE,NBVISITES,MARQUE,CIN,PANNE,MODELE) "
                      "VALUES (:1,:4,:2,:3,:5,:6)");

         query.bindValue(":1", matricule);
         query.bindValue(":4", nbr_visite_string);
         query.bindValue(":2", marque);
         query.bindValue(":3", cin_prop);
         query.bindValue(":5", panne);
         query.bindValue(":6", modele);

         return query.exec();


}

bool Voiture::vider_archive() //all
{
    QSqlQuery query;

    query.prepare("Delete from ZARCHIVE");


    return query.exec();


}

bool Voiture::supprimer_archive(QString)
{
    QSqlQuery query;

    query.prepare("Delete from ZARCHIVE where MATRICULE= :mat");

    query.bindValue(":mat",matricule);


    return query.exec();


}


QSqlQueryModel * Voiture ::AfficherTrimarque()
{
QSqlQueryModel *model = new QSqlQueryModel;
     model->setQuery("SELECT * FROM GVOITURE ORDER BY MARQUE ASC , NBVISITES ASC ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("VISITES"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("MARQUE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("PANNE"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("MODELE"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("AFFECTATION"));
return model;
     }

bool Voiture ::update_personnel(QString q)
{
    QSqlQuery query;
    QString msg="NON DISPONIBLE";

    query.prepare("UPDATE PERSSONEL SET ETATEMP=:ETAT WHERE NOMEMP=:nom ");
     query.bindValue(":nom",q);

    query.bindValue(":ETAT",msg);

    return query.exec();

}

bool Voiture ::update_affectation(QString p)
{
    QSqlQuery query;

    QString msg="AFFECTEE";

    query.prepare("UPDATE GVOITURE SET AFFECTATION=:AFFECTATION WHERE MATRICULE=:nom ");
     query.bindValue(":nom",p);

    query.bindValue(":AFFECTATION",msg);
    return query.exec();

}

int Voiture ::row_count()
{

    int numberOfRows =0;
        QSqlQuery query;
        query.exec("SELECT * FROM GVOITURE ");
        while(query.next())
        { numberOfRows++;}
    query.exec();

        /*QString ch=QString::number(numberOfRows);
        QMessageBox msgBox;
        msgBox.setText(ch);
        msgBox.exec();*/

        return numberOfRows;

}
