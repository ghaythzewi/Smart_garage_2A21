#ifndef FACTURE_H
#define FACTURE_H
#include <QString>
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <QSqlQueryModel>
#include <QPlainTextEdit>
#include <QDateTime>
//Include Stats
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QSqlQueryModel>
class Facture
{
public:
    Facture();
    Facture(int,QString,float,QString,QString,QString);
    int getrefernce();
    QString getclient();
    Facture *getcin20(int);
    QSqlQueryModel * getcins33();
    float getmontant();
    QString getcaissier();
    QString getdate();
    QString getachats();
    void setreference (int);
    void setclient (QString);
    void setmontant (float);
    void setcaissier (QString);
    void setdate (QString);
    void setachats (QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int reference,QString client,float montant,QString achats,QString caissier,QString date);
     QSqlQueryModel* tri_reference();
      QSqlQueryModel* rechercher(const QString &aux);
private:
    int reference;
    QString client;
    float montant;
    QString caissier;
    QString date;
    QString achats;
};

#endif // FACTURE_H
