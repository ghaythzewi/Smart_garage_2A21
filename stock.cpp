#include "stock.h"
#include<qsqlquery.h>
#include<QtDebug>
#include<qsqlquery.h>
#include<QSqlRecord>
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

QSqlQueryModel  * Stock::recherche(QString recherche)
{
QSqlQueryModel * model= new QSqlQueryModel();
QString res= QString::number(numserie);

model->setQuery("SELECT * FROM Stock WHERE numserie LIKE '"+recherche+"%' OR marque LIKE '"+recherche+"%' OR NOM LIKE '"+recherche+"%'");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantité "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date import"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("fournisseur"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("numserie"));
return    model;
}
///////////////////////

/*model->setQuery("SELECT * FROM FOURNISSEUR WHERE ID LIKE '"+recherche+"%' OR TEL LIKE '"+recherche+"%' OR NOM LIKE '"+recherche+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Mail "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("fidelité"));
    return model;
}*/


/////////////////////////
QSqlQueryModel *Stock::afficher_trier( QString type,QString facon)
{    QSqlQueryModel *model =new QSqlQueryModel();
     QSqlQuery query ;

      model->setQuery("SELECT * FROM Stock ORDER BY "+type+" "+facon+"");


       return model ;

}

bool Stock::EXCEL()
{
    QSqlQuery q("select * from stock");
      QSqlRecord rec = q.record();

      QFile fichier("C:/Users/MSI/Desktop/excel/result.csv");

      if(fichier.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
      {
          QTextStream stream(&fichier);

      int nomCol = rec.indexOf("nom"); // index of the field "name"
      int marqueCol = rec.indexOf("marque"); // index of the field "name"
      int fournisseurCol = rec.indexOf("fournisseur"); // index of the field "name"
      int numserieCol = rec.indexOf("numserie"); // index of the field "name"
      int prixCol = rec.indexOf("prix"); // index of the field "name"
      int dateimportationCol = rec.indexOf("dateimportation"); // index of the field "name"
      int quantiteCol = rec.indexOf("quantite"); // index of the field "name"
      stream << "Nom" << ";" << "marque" << ";" << "fournisseur" << ";" << "numserie" << ";" << "prix" << ";" << "dateimportation" ";" << "quantite"  <<"\n";

      while (q.next())
          stream  << q.value(nomCol).toString() << ";" << q.value(marqueCol).toString() << ";" << q.value(fournisseurCol).toString() << ";" << q.value(numserieCol).toString()<< ";" << q.value(prixCol).toString() << ";" << q.value(dateimportationCol).toString() << ";" << q.value(quantiteCol).toString() << "\n";
    fichier.close();
    }












}
