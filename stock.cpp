#include "stock.h"
#include<qsqlquery.h>
#include<QtDebug>
#include<qsqlquery.h>
Stock::Stock()
{
this->nom="";
this->marque="";
this->fournisseur="";
this->quantite=0;
this->prix=0;
this->dateimport="";
this->numserie=0;
}
Stock::Stock(QString nom,QString marque,int prix,QString dateimport,QString fournisseur,int quantite,int numserie)
{
    this->nom=nom;
    this->marque=marque;
    this->fournisseur=fournisseur;
    this->quantite=quantite;
    this->prix=prix;
    this->dateimport=dateimport;
    this->numserie=numserie;

}

bool Stock::Ajouter(){



    QSqlQuery query;
          query.prepare("INSERT INTO STOCK (NOM, MARQUE, fournisseur, prix, dateimport, quantite,numserie) "
                        "VALUES (?, ?, ?, ? , ?, ?, ?)");
          query.addBindValue(nom);
          query.addBindValue(marque);
          query.addBindValue(fournisseur);
          query.addBindValue(prix);
          query.addBindValue(dateimport);
          query.addBindValue(quantite);
          query.addBindValue(numserie);


         return query.exec();
}


bool Stock::supprimer()
{
QSqlQuery query;
//QString res= QString::number(cin);
query.prepare("Delete from Stock where nom = :nom AND marque = :marque");
query.bindValue(":nom", nom);
query.bindValue(":marque", marque);
return    query.exec();
}
void Stock::setmarque(QString marque)
{
this->marque=marque;
}

void Stock::setnom(QString nom)
{
this->nom=nom;
}

QSqlQueryModel * Stock::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from stock");
    return model;
}


bool Stock::modifier()
{

QSqlQuery query;



    query.prepare("update stock set  fournisseur=?, prix=?, dateimport=?, quantite=? where numserie=?");

    query.addBindValue(fournisseur);
    query.addBindValue(prix);
    query.addBindValue(dateimport);
    query.addBindValue(quantite);
    query.addBindValue(numserie);





return    query.exec();
}

