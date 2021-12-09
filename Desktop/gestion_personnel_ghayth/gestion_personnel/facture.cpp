#include "facture.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <iostream>
#include <QSqlQueryModel>
Facture::Facture()
{
reference=0; client=" "; montant=0.0f; caissier=" "; date=" "; achats=" ";

}
Facture::Facture(int reference,QString client,float montant,QString caissier,QString date,QString achats)
{this->reference=reference;this->client=client;this->montant=montant;this->caissier=caissier;this->date=date;this->achats=achats;}
int Facture::getrefernce(){return reference;}
QString Facture::getclient(){return client;}
float Facture::getmontant(){return montant;}
QString Facture::getcaissier(){return caissier;}
QString Facture::getdate(){return date;}
QString Facture::getachats(){return achats;}
void Facture::setreference (int reference){this->reference=reference;}
void Facture::setclient (QString client){this->client=client;}
void Facture::setmontant (float montant){this->montant=montant;}
void Facture::setcaissier (QString caissier){this->caissier=caissier;}
void Facture::setdate (QString date){this->date=date;}
void Facture::setachats (QString achats){this->achats=achats;}
bool Facture::ajouter()
{

    QString reference_string= QString::number(reference);
    QString montant_string=QString::number(montant);
    QSqlQuery query;
          query.prepare("INSERT INTO FACTURE (reference,client,montant,achat,caissier,date_heure) "
                        "VALUES (:reference,:client,:montant,:achats,:caissier,:date)");
          query.bindValue(":reference", reference_string);
          query.bindValue(":client", client);
          query.bindValue(":montant", montant_string);
          query.bindValue(":achat", achats);
          query.bindValue(":caissier", caissier);
          query.bindValue(":date_heure", date);
 return query.exec();
}
bool Facture::supprimer(int reference){
    QSqlQuery query;
          query.prepare("delete from facture where reference=:reference");
          query.bindValue(0, reference);

 return query.exec();



}
QSqlQueryModel* Facture::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery("SELECT* FROM facture");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("client"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("achat"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("caissier"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_heure"));
 return model;
}
bool Facture::modifier(int reference,QString client,float montant,QString achats,QString caissier,QString date)

{

    QString reference_string= QString::number(reference);
    QString montant_string=QString::number(montant);

    QSqlQuery query;
       query.prepare("update facture set client=:client,montant=:montant,achat=:achats,caissier=:caissier,date_heure=:date where reference=:reference");


       query.bindValue(":reference", reference_string);
       query.bindValue(":client", client);
       query.bindValue(":montant", montant_string);
       query.bindValue(":achat", achats);
       query.bindValue(":caissier", caissier);
       query.bindValue(":date_heure", date);
return query.exec();
}


 QSqlQueryModel *Facture::tri_reference()
 {
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from  facture ORDER BY reference");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("client"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("achat"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("caissier"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_heure"));
return model;
 }


 QSqlQueryModel* Facture::rechercher (const QString &aux)

 {
     QSqlQueryModel* model = new QSqlQueryModel();

     model->setQuery("select * from facture where ((reference||client||montant||achat||caissier||date_heure) LIKE '%"+aux+"%')");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("client"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("achat"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("caissier"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_heure"));

     return model;

 }
