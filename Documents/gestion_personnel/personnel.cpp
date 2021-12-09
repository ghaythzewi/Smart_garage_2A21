#include "personnel.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QPdfWriter>
#include<QPainter>


#include "connection.h"
personnel::personnel()
{
    cin_emp=0;
    nbr_conge_emp=0;
    tel_emp=0;
    nom_emp=" " ;
    prenom_emp=" " ;
    id_emp=" " ;
    parking_emp=" ";
    etat_emp=" ";
    Specialite_emp=" ";
}
personnel::personnel(int cin_emp,QString nom_emp,QString prenom_emp,QString id_emp,QString parking_emp,int nbr_conge_emp,int tel_emp,QString etat_emp,QString Specialite_emp,QDate date_emp)
{
    this->cin_emp=cin_emp;
    this->nom_emp=nom_emp;
    this->prenom_emp=prenom_emp;
    this->id_emp=id_emp;
    this->parking_emp=parking_emp;
    this->tel_emp=tel_emp;
    this->nbr_conge_emp=nbr_conge_emp;
    this->etat_emp=etat_emp;
    this->Specialite_emp=Specialite_emp;
    this->daate_emp = date_emp ;
}
int personnel::getcin_emp(){return cin_emp;}
QString personnel::getnom_emp(){return nom_emp ;}
QString personnel::getprenom_emp(){return prenom_emp ;}
QString personnel::getid_emp(){return id_emp;}
QString personnel::getparking_emp(){return parking_emp;}
int personnel::gettel_emp(){return tel_emp;}
int personnel::getnbr_conge_emp(){return nbr_conge_emp;}
QString personnel::getetat_emp(){return  etat_emp;}
QString personnel::getSpecialite_emp(){return Specialite_emp;}
QDate personnel::getdaate_emp(){return daate_emp;}
void personnel::setcin_emp(int cin_emp){this->cin_emp=cin_emp;}
void personnel::setnom_emp(QString nom_emp){this->nom_emp=nom_emp;}
void personnel::setprenom_emp(QString prenom_emp){this->prenom_emp=prenom_emp;}
void personnel::setid_emp(QString id_emp){this->id_emp=id_emp;}
void personnel::setparking_emp(QString parking_emp){this->parking_emp=parking_emp;}
void personnel::settel_emp(int tel_emp){this->tel_emp=tel_emp;}
void personnel::setnbr_conge_emp(int nbr_conge_emp){this->nbr_conge_emp=nbr_conge_emp;}
void personnel::setetat_emp(QString etat_emp){this->etat_emp=etat_emp;}
void personnel::setSpecialite_emp(QString Specialite_emp){this->Specialite_emp=Specialite_emp;}
void personnel::setdaate_emp(QDate daate_emp){this->daate_emp=daate_emp;}

//----------------------ajout
bool personnel::ajouter_emp()
{

    bool test=false;
    QString cin_string= QString::number(cin_emp);
    QString tel_string= QString::number(tel_emp);
    QString nbr_conge_string= QString::number(nbr_conge_emp);
    QSqlQuery query;
          query.prepare("INSERT INTO PERSSONEL (CINEMP, NOMEMP, PRENOMEMP, TELEMP, NBR_CONGEEMP , ETATEMP, SPECIALITEEMP,DAATEEMP, IDEMP, PARKINGEMP ) "
                        "VALUES (:CINEMP, :NOMEMP, :PRENOMEMP, :TELEMP, :NBR_CONGEEMP,:ETATEMP, :SPECIALITEEMP,:DAATEEMP , :IDEMP, :PARKINGEMP)");
          query.bindValue(":CINEMP", cin_string);
          query.bindValue(":NOMEMP", nom_emp);
          query.bindValue(":PRENOMEMP", prenom_emp);

          query.bindValue(":TELEMP", tel_string);
          query.bindValue(":NBR_CONGEEMP", nbr_conge_string);
          query.bindValue(":ETATEMP", etat_emp);
          query.bindValue(":SPECIALITEEMP",Specialite_emp);
          query.bindValue(":DAATEEMP",daate_emp);
          query.bindValue(":IDEMP", id_emp);
          query.bindValue(":PARKINGEMP", parking_emp);
          test=true;
          query.exec();

    return test;
}

//------------------supprimer
bool personnel::supprimer_emp(int cin_emp)
{bool test=false;
    QString cin_emp_string= QString::number(cin_emp);

    QSqlQuery query;

          query.prepare("Delete from PERSSONEL where CINEMP=:CINEMP");

          query.bindValue(":CINEMP", cin_emp_string);
          test = true ;

          query.exec();
          return test;
}

//------------modifier
bool personnel::modifier_emp(int cin_emp ,QString nom_emp, QString prenom_emp,QString  id_emp,QString parking_emp, int tel_emp,int nbr_conge_emp,QString etat_emp,QString Specialite_emp,QDate daate_emp)
{
    bool test=false;
    QSqlQuery query;
    query.prepare("UPDATE PERSSONEL SET CINEMP= :CINEM,NOMEMP= :NOMEMP,PRENOMEMP= :PRENOMEMP, TELEMP= :TELEMP,NBR_CONGEEMP= :NBR_CONGEEMP,ETATEMP= :ETATEMP,SPECIALITEEMP= :SPECIALITEEMP,DAATEEMP= :DAATEEMP, IDEMP= :IDEMP, PARKINGEMP= :PARKINGEMP  where CINEMP= :CINEMP ");
    query.bindValue(":CINEMP", cin_emp);
    query.bindValue(":NOMEMP", nom_emp);
    query.bindValue(":PRENOM", prenom_emp);
    query.bindValue(":TELEMP", tel_emp);
    query.bindValue(":NBR_CONGEEMP", nbr_conge_emp);
    query.bindValue(":ETATEMP", etat_emp);
    query.bindValue(":SPECIALITEEMP",Specialite_emp);
    query.bindValue(":DAATEEMP",daate_emp);
    query.bindValue(":IDEMP", id_emp);
    query.bindValue(":PARKINGEMP", parking_emp);
    test=true;
    query.exec();
    return test;
}

//-----------afficher
QSqlQueryModel* personnel::afficher_emp()
{
    Connection c;
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM PERSSONEL");
          model->setHeaderData(0, Qt::Horizontal,QObject:: tr("CINEMP"));
          model->setHeaderData(1, Qt::Horizontal,QObject:: tr("NOMEMP"));
          model->setHeaderData(2, Qt::Horizontal,QObject:: tr("PRENOMEMP"));
          model->setHeaderData(3, Qt::Horizontal,QObject:: tr("TELEMP"));
          model->setHeaderData(4, Qt::Horizontal,QObject:: tr("NBR_CONGEEMP"));
          model->setHeaderData(5, Qt::Horizontal,QObject:: tr("ETATEMP"));
           model->setHeaderData(6, Qt::Horizontal,QObject:: tr("SPECIALITEEMP"));
           model->setHeaderData(7, Qt::Horizontal,QObject:: tr("DAATEEMP"));
           model->setHeaderData(8, Qt::Horizontal,QObject:: tr("IDEMP"));
           model->setHeaderData(9, Qt::Horizontal,QObject:: tr("PARKINGEMP"));
    return model;

}

//---------------tri
QSqlQueryModel* personnel::trier_emp()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM PERSSONEL ORDER BY prenomEMP ASC");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("CINEMP"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("NOMEMP"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("PRENOMEMP"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("TELEMP"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("NBR_CONGEEMP"));
    model->setHeaderData(5, Qt::Horizontal,QObject:: tr("ETATEMP"));
    model->setHeaderData(6, Qt::Horizontal,QObject:: tr("SPECIALITEEMP"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("DAATEEMP"));
    model->setHeaderData(8, Qt::Horizontal,QObject:: tr("IDEMP"));
    model->setHeaderData(9, Qt::Horizontal,QObject:: tr("PARKINGEMP"));
    return model;
}

QSqlQueryModel* personnel::trierparnom_emp()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM PERSSONEL ORDER BY NOMEMP ASC");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("CINEMP"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("NOMEMP"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("PRENOMEMP"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("TELEMP"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("NBR_CONGEEMP"));
    model->setHeaderData(5, Qt::Horizontal,QObject:: tr("ETATEMP"));
    model->setHeaderData(6, Qt::Horizontal,QObject:: tr("SPECIALITEEMP"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("DAATEEMP"));
    model->setHeaderData(8, Qt::Horizontal,QObject:: tr("IDEMP"));
    model->setHeaderData(9, Qt::Horizontal,QObject:: tr("PARKINGEMP"));
    return model;
}
//----------recherche
QSqlQueryModel* personnel::recherche_emp(QString nom_emp)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QString query = "SELECT * FROM PERSSONEL ";
    if(nom_emp != "") {
        query = query + "WHERE NOM LIKE '%" + nom_emp +"%'";
    }
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("CINEMP"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("NOMEMP"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("PRENOMEMP"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("TELEMP"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("NBR_CONGEEMP"));
    model->setHeaderData(5, Qt::Horizontal,QObject:: tr("ETATEMP"));
    model->setHeaderData(6, Qt::Horizontal,QObject:: tr("SPECIALITEEMP"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("DAATEEMP"));
    model->setHeaderData(8, Qt::Horizontal,QObject:: tr("IDEMP"));
    model->setHeaderData(9, Qt::Horizontal,QObject:: tr("PARKINGEMP"));
    return model;
}
//-------------pdf
bool personnel::genererPDFproduit_emp()
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
