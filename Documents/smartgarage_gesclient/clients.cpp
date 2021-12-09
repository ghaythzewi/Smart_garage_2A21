#include "clients.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QString>


clients::clients()
{
CIN=0 ;nom="  ";prenom=" ";tel=0;mail="  ";adresse="  ";
}

clients::clients(int CIN,QString nom,QString prenom,int tel,QString mail,QString adresse)
{this->CIN=CIN; this->nom=nom;this->prenom=prenom;this->tel=tel;this->mail=mail;this->adresse=adresse;}
    int clients::getCIN(){return CIN;}

    QString clients::getnom(){return nom;}
    QString clients::getprenom(){return prenom;}
        int clients::gettel(){return tel;}
    QString clients::getmail(){return mail;}
    void clients:: setCIN(int CIN){this->CIN=CIN;}
    void clients::setnom(QString nom){this->nom=nom;}
    void clients::setprenom(QString prenom){this->prenom=prenom;}
     void clients::settel(int tel){this->tel=tel;}
    void clients::setmail(QString mail){this->mail=mail;}
    void clients::setadresse(QString adresse){this->adresse=adresse;}
    bool clients::ajouter()
    {
        QSqlQuery query;
        QString res =QString::number(CIN);
        QString res1 =QString::number(tel);

              query.prepare("INSERT INTO GESTIONCLIENT (CIN,nom,prenom, tel,mail,adresse) "
                            "VALUES (:CIN, :nom,:prenom,:tel,:mail,:adresse)");
              query.bindValue(":CIN", res);
              query.bindValue(":nom", nom);
              query.bindValue(":prenom", prenom);
               query.bindValue(":tel", res1);
              query.bindValue(":mail", mail);
              query.bindValue(":adresse", adresse);



    return query.exec();
    }

    QSqlQueryModel* clients::afficher()
              {
                 QSqlQueryModel* model=new QSqlQueryModel();
                       model->setQuery("SELECT* FROM GESTIONCLIENT");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
                return model;
              }

              bool  clients::supprimer(int CIN)
              {  QSqlQuery query;
                  QString res=QString::number(CIN);
                  query.prepare("delete from GESTIONCLIENT where CIN=:CIN");
                query.bindValue(":CIN",CIN);
              return query.exec();


              }



              bool clients::update(int CIN, QString nom, QString prenom, int tel, QString mail, QString adresse)
              {
                  QSqlQuery query;

                  query.prepare("UPDATE GESTIONCLIENT SET nom= :nom,prenom= :prenom, tel= :tel, mail= :mail,CIN=:CIN, adresse= :adresse WHERE CIN =:CIN");
                  query.bindValue(":CIN", CIN);
                  query.bindValue(":nom", nom);
                  query.bindValue(":prenom", prenom);
                  query.bindValue(":tel", tel);
                  query.bindValue(":mail", mail);
                  query.bindValue(":adresse", adresse);


                          return    query.exec();

              }

