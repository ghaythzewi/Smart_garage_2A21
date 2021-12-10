#ifndef STOCK_H
#define STOCK_H
#include<qstring.h>
#include<qsqlquerymodel.h>
#include <QSqlQuery>
#include <QFrame>
#include <QtCharts/QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
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
    QSqlQueryModel  * recherche(QString );
    QSqlQueryModel * afficher_trier( QString type,QString facon);
    bool EXCEL();


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
