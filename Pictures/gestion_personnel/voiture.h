#ifndef VOITURE_H
#define VOITURE_H
#include<QString>
#include<QSqlQueryModel>
class Voiture
{
public:
    Voiture();
    Voiture(QString,QString,int,QString,QString,QString,QString);
QString getmatricule();
QString getmarque();
QString getpanne();
QString getmodele();
int getnbr();
QString getcin();
QString getaffect();
void setmatricule(QString);
void setmarque(QString);
void setpanne(QString);
void setmodele(QString);
void setnbr(int);
void setcin(QString);
void setaffect(QString);
bool ajouter();
QSqlQueryModel * afficher();
QSqlQueryModel * getcins();
bool supprimer(QString);
bool modifier(QString);
Voiture*getcin2(int);
QSqlQueryModel * archive();
bool ajouter_archive();
bool vider_archive();
bool supprimer_archive(QString);
QSqlQueryModel * AfficherTrimarque();
bool update_personnel(QString);
bool update_affectation(QString);
int row_count();


private :
    QString matricule,marque,panne,modele;
    int nb_visites;
    QString cin_prop,affectation;
};

#endif // VOITURE_H
