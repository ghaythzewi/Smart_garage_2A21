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
    int getcin_emp();
    QString getnom_emp();
    QString getprenom_emp();
    QString getid_emp();
    QString getparking_emp();
    int getnbr_conge_emp();
    int gettel_emp();
    QString getetat_emp();
    QString getSpecialite_emp();
    QDate getdaate_emp();
    void setcin_emp(int);
    void setprenom_emp(QString);
    void setnom_emp(QString);
    void setid_emp(QString);
    void setparking_emp(QString);
    void setnbr_conge_emp(int);
    void settel_emp(int);
    void setetat_emp(QString);
    void setSpecialite_emp(QString);
    void setdaate_emp(QDate);
    bool ajouter_emp();
    QSqlQueryModel* afficher_emp();
    bool supprimer_emp(int);
    bool modifier_emp(int ,QString , QString ,QString  ,QString , int ,int,QString,QString,QDate );
    QSqlQueryModel* trierparnom_emp();
    QSqlQueryModel* trier_emp();
    QSqlQueryModel* recherche_emp(QString);
    bool genererPDFproduit_emp();
private:
    int cin_emp ;
    QString nom_emp ;
    QString prenom_emp ;
    QString id_emp ;
    QString parking_emp;
    int nbr_conge_emp;
    int tel_emp;
    QString etat_emp ;
    QString Specialite_emp;
    QDate daate_emp;

};

#endif // PERSONNEL_H
