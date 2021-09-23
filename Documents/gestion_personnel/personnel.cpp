#include "personnel.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QPdfWriter>
#include<QPainter>


#include "connection.h"
personnel::personnel()
{
    cin=0;
    nbr_conge=0;
    tel=0;
    nom=" " ;
    prenom=" " ;
    mail=" " ;
    adresse=" ";
    etat=" ";
    Specialite=" ";
}
personnel::personnel(int cin,QString nom,QString prenom,QString mail,QString adresse,int nbr_conge,int tel,QString etat,QString Specialite,QDate date)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->mail=mail;
    this->adresse=adresse;
    this->tel=tel;
    this->nbr_conge=nbr_conge;
    this->etat=etat;
    this->Specialite=Specialite;
    this->daate = date ;
}
int personnel::getcin(){return cin;}
QString personnel::getnom(){return nom ;}
QString personnel::getprenom(){return prenom ;}
QString personnel::getmail(){return mail;}
QString personnel::getadresse(){return adresse;}
int personnel::gettel(){return tel;}
int personnel::getnbr_conge(){return nbr_conge;}
QString personnel::getetat(){return  etat;}
QString personnel::getSpecialite(){return Specialite;}
QDate personnel::getdaate(){return daate;}
void personnel::setcin(int cin){this->cin=cin;}
void personnel::setnom(QString nom){this->nom=nom;}
void personnel::setprenom(QString prenom){this->prenom=prenom;}
void personnel::setmail(QString mail){this->mail=mail;}
void personnel::setadresse(QString adresse){this->adresse=adresse;}
void personnel::settel(int tel){this->tel=tel;}
void personnel::setnbr_conge(int nbr_conge){this->nbr_conge=nbr_conge;}
void personnel::setetat(QString etat){this->etat=etat;}
void personnel::setSpecialite(QString Specialite){this->Specialite=Specialite;}
void personnel::setdaate(QDate daate){this->daate=daate;}

//----------------------ajout
bool personnel::ajouter()
{

    bool test=false;

    QString cin_string= QString::number(cin);
    QString tel_string= QString::number(tel);
    QString nbr_conge_string= QString::number(nbr_conge);
    QSqlQuery query;
          query.prepare("INSERT INTO PERSSONEL (CIN, NOM, PRENOM, MAIL, ADRESSE, TEL, NBR_CONGE , ETAT, SPECIALITE,DAATE ) "
                        "VALUES (:CIN, :NOM, :PRENOM, :MAIL, :ADRESSE, :TEL, :NBR_CONGE,:ETAT, :SPECIALITE,:DAATE )");
          query.bindValue(":CIN", cin_string);
          query.bindValue(":NOM", nom);
          query.bindValue(":PRENOM", prenom);
          query.bindValue(":MAIL", mail);
          query.bindValue(":ADRESSE", adresse);
          query.bindValue(":TEL", tel_string);
          query.bindValue(":NBR_CONGE", nbr_conge_string);
          query.bindValue(":ETAT", etat);
          query.bindValue(":SPECIALITE",Specialite);
          query.bindValue(":DAATE",daate);
          test=true;
          query.exec();

    return test;
}

//------------------supprimer
bool personnel::supprimer(int cin)
{bool test=false;
    QString cin_string= QString::number(cin);

    QSqlQuery query;

          query.prepare("Delete from PERSSONEL where CIN=:CIN");

          query.bindValue(":CIN", cin_string);
          test = true ;

          query.exec();
          return test;
}

//------------modifier
bool personnel::modifier(int cin ,QString nom, QString prenom,QString  mail,QString adresse, int tel,int nbr_conge,QString etat,QString Specialite,QDate daate)
{
    bool test=false;
    QSqlQuery query;
    query.prepare("UPDATE PERSSONEL SET CIN= :CIN,NOM= :NOM,PRENOM= :PRENOM, MAIL= :MAIL, ADRESSE= :ADRESSE, TEL= :TEL,NBR_CONGE= :NBR_CONGE,ETAT= :ETAT,SPECIALITE= :SPECIALITE,DAATE= :DAATE  where CIN= :CIN ");
    query.bindValue(":CIN", cin);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":MAIL", mail);
    query.bindValue(":ADRESSE", adresse);
    query.bindValue(":TEL", tel);
    query.bindValue(":NBR_CONGE", nbr_conge);
    query.bindValue(":ETAT", etat);
    query.bindValue(":SPECIALITE",Specialite);
    query.bindValue(":DAATE",daate);
    test=true;
    query.exec();
    return test;
}

//-----------afficher
QSqlQueryModel* personnel::afficher()
{
    Connection c;
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM PERSSONEL");
          model->setHeaderData(0, Qt::Horizontal,QObject:: tr("CIN"));
          model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
          model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal,QObject:: tr("mail"));
          model->setHeaderData(4, Qt::Horizontal,QObject:: tr("adresse"));
          model->setHeaderData(5, Qt::Horizontal,QObject:: tr("telephone"));
          model->setHeaderData(6, Qt::Horizontal,QObject:: tr("nbr de conge"));
          model->setHeaderData(7, Qt::Horizontal,QObject:: tr("Etat"));
           model->setHeaderData(8, Qt::Horizontal,QObject:: tr("SPECIALITE"));
           model->setHeaderData(9, Qt::Horizontal,QObject:: tr("DAATE"));
    return model;

}

//---------------tri
QSqlQueryModel* personnel::trier()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM PERSSONEL ORDER BY prenom ASC");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("mail"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("adresse"));
    model->setHeaderData(5, Qt::Horizontal,QObject:: tr("telephone"));
    model->setHeaderData(6, Qt::Horizontal,QObject:: tr("nbr de conge"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("Etat"));
    model->setHeaderData(8, Qt::Horizontal,QObject:: tr("SPECIALITE"));
    model->setHeaderData(9, Qt::Horizontal,QObject:: tr("DAATE"));
    return model;
}

QSqlQueryModel* personnel::trierparnom()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM PERSSONEL ORDER BY NOM ASC");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("mail"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("adresse"));
    model->setHeaderData(5, Qt::Horizontal,QObject:: tr("telephone"));
    model->setHeaderData(6, Qt::Horizontal,QObject:: tr("nbr de conge"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("Etat"));
    model->setHeaderData(8, Qt::Horizontal,QObject:: tr("SPECIALITE"));
    model->setHeaderData(9, Qt::Horizontal,QObject:: tr("DAATE"));
    return model;
}
//----------recherche
QSqlQueryModel* personnel::recherche(QString nom)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QString query = "SELECT * FROM PERSSONEL ";
    if(nom != "") {
        query = query + "WHERE NOM LIKE '%" + nom +"%'";
    }
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("mail"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("adresse"));
    model->setHeaderData(5, Qt::Horizontal,QObject:: tr("telephone"));
    model->setHeaderData(6, Qt::Horizontal,QObject:: tr("nbr de conge"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("Etat"));
    model->setHeaderData(8, Qt::Horizontal,QObject:: tr("SPECIALITE"));
    model->setHeaderData(9, Qt::Horizontal,QObject:: tr("DAATE"));
    return model;
}
//-------------pdf
bool personnel::genererPDFproduit()
{
    QPdfWriter pdf("C:\\Users\\hp\\Documents\\gestion_personnel\\pdf.pdf");
    QPainter painter(&pdf);
                        int i = 4000;
                             painter.setPen(Qt::green);
                             painter.setFont(QFont("Arial", 50));
                             painter.drawText(1100,1200,"Liste des Perssonel");
                             painter.setPen(Qt::red);
                             painter.setFont(QFont("Arial", 15));
                             painter.drawRect(500,100,7700,2600);
                             painter.drawRect(2200,3000,4000,500);
                             painter.setFont(QFont("Arial", 9));
                             painter.drawText(2400,3300,"cin");
                             painter.drawText(3500,3300,"nom");
                             painter.drawText(4600,3300,"prenom");
                             painter.drawText(5700,3300,"mail");
                             painter.drawText(5700,3300,"adresse");
                             painter.drawText(5700,3300,"etat");
                             painter.drawText(5700,3300,"Specialite");
                             QSqlQuery query;

                                                         query.prepare("select * from PERSSONEL");
                                                         query.exec();
                                                         while (query.next())
                                                         {
                                                             painter.drawText(1400,i,query.value(1).toString());
                                                             painter.drawText(2400,i,query.value(2).toString());
                                                             painter.drawText(3400,i,query.value(3).toString());
                                                             painter.drawText(4400,i,query.value(4).toString());
                                                             painter.drawText(5400,i,query.value(5).toString());
                                                             painter.drawText(6400,i,query.value(6).toString());
                                                             painter.drawText(7400,i,query.value(7).toString());
                                                             painter.drawText(8400,i,query.value(8).toString());
                                                             painter.drawText(9400,i,query.value(9).toString());
                                                             painter.drawText(10400,i,query.value(10).toString());
                                                            i = i + 500;

                                                         }
 return query.exec();}
