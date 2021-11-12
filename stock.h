#ifndef STOCK_H
#define STOCK_H
#include<qstring.h>
#include<qsqlquerymodel.h>
class Stock
{
public:
    Stock();
    Stock(QString nom,QString marque,int prix,QString dateimport,QString fournisseur,int quantite,int numserie);
    bool Ajouter();
    bool supprimer();
    void setmarque(QString marque);
    void setnom(QString nom);
    QSqlQueryModel * afficher();
    bool modifier();



private:
    QString nom;
    QString marque;
    QString fournisseur;
    int prix;
    int quantite;
    QString dateimport;
    int numserie;
};

#endif // STOCK_H
