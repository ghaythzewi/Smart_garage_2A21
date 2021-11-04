#include "clients.h"
#include <QSqlQuery>
#include <QtDebug>

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
