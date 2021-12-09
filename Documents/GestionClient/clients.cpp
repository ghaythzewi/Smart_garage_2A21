#include "clients.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QString>

clients::clients()
{CIN=0 ;nom="  ";prenom=" ";tel=0;mail="  ";adresse="  ";}



clients::clients(int CIN,int tel,QString nom,QString prenom,QString mail,QString adresse)
{this->CIN=CIN; this->nom=nom;this->prenom=prenom;this->tel=tel;this->mail=mail;this->adresse=adresse;}
    int clients::getCIN(){return CIN;}
    int clients::gettel(){return tel;}
    QString clients::getnom(){return nom;}
    QString clients::getprenom(){return prenom;}
    QString clients::getmail(){return mail;}
    void clients:: setCIN(int CIN){this->CIN=CIN;}
    void clients::setnom(QString nom){this->nom=nom;}
    void clients::setprenom(QString prenom){this->prenom=prenom;}
    void clients::setmail(QString mail){this->mail=mail;}
    void clients::setadresse(QString adresse){this->adresse=adresse;}
    bool clients::ajouter()
    {
        QSqlQuery query;
        QString res =QString::number(CIN);
        QString res1 =QString::number(tel);

              query.prepare("INSERT INTO clients (CIN,tel,nom, prenom,mail,adresse) "
                            "VALUES (:CIN, :tel, :nom:prenom,:mail,:adresse)");
              query.bindValue(":CIN", res);
              query.bindValue(":tel", res1);
              query.bindValue(":nom", nom);
              query.bindValue(":prenom", prenom);
              query.bindValue(":mail", mail);
              query.bindValue(":adresse", adresse);



    return query.exec();
    }


              QSqlQueryModel* clients::afficher()
              {
                 QSqlQueryModel* model=new QSqlQueryModel();
                       model->setQuery("SELECT* FROM clients");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("tel"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
                return model;
              }

              bool  clients::supprimer(int CIN)
              {  QSqlQuery query;
                  QString res=QString::number(CIN);
                  query.prepare("delete from clients where CIN=:CIN");
                query.bindValue(":CIN",res);
              return query.exec();


              }
