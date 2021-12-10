#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <QString>
#include <QSqlQueryModel>
#include <QDate>
class personnel
{
public:
    personnel();
    personnel(int,QString,QString,QString,QString,int,int,QString,QString,QDate);
    int getcin();
    QString getnom();
    QString getprenom();
    QString getmail();
    QString getadresse();
    int getnbr_conge();
    int gettel();
    QString getetat();
    QString getSpecialite();
    QDate getdaate();
    void setcin(int);
    void setprenom(QString);
    void setnom(QString);
    void setmail(QString);
    void setadresse(QString);
    void setnbr_conge(int);
    void settel(int);
    void setetat(QString);
    void setSpecialite(QString);
    void setdaate(QDate);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int ,QString , QString ,QString  ,QString , int ,int,QString,QString,QDate );
    QSqlQueryModel* trierparnom();
    QSqlQueryModel* trier();
    QSqlQueryModel* recherche(QString);
    bool genererPDFproduit();
private:
    int cin ;
    QString nom ;
    QString prenom ;
    QString mail ;
    QString adresse;
    int nbr_conge;
    int tel;
    QString etat ;
    QString Specialite;
    QDate daate;

};

#endif // PERSONNEL_H
