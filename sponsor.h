#ifndef SPONSOR_H
#define SPONSOR_H


#include<QSqlQueryModel>
#include<QPainter>


class Sponsor
{
public:

   Sponsor();
   Sponsor(QString,QString,int,int);

   int getcin();
   int gettel();

    QString getsexe();
   QString getnom();
   QString getprenom();

   void setcin(int);
   void settel(int);

   void setsexe(QString);
   void setnom(QString);
   void setprenom(QString);

bool rechercher(int);

    bool ajouter();
    QSqlQueryModel * afficher();
 bool modifierj(int cin ,QString nom ,QString prenom, int tel);
  bool supprimer(int);
QSqlQueryModel * rechercher (const QString &aux);
void genererPDF();
   private :
   QString nom,prenom;

   int CIN, tel;

   QString fonction;
};
#endif // SPONSOR_H
