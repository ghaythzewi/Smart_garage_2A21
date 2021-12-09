#ifndef CLIENTS_H
#define CLIENTS_H
#include <QString>
#include<QSqlQueryModel>
#include <QDialog>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QTableView>
#include <QPainter>
//#include <QChart>
//#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>


using namespace QtCharts;
class Clients
{
public:
    Clients();
     Clients(int,QString,QString,int ,  QString ,QString);
int getcin ();
QString getnom() ;
QString getprenom() ;
int gettel () ;
QString getmail() ;
QString getadresse();
void setcin(int);
void setnom(QString);
void setprenom(QString);
void settel(int);
void setmail(QString);
void setadresse(QString);
bool ajouter();
 bool supprimer(int);

   QSqlQueryModel *afficher();
   bool update(int,QString,QString,int ,  QString,QString);
   QSqlQueryModel* rechercher(const QString &aux);
   void recherche(QTableView * table, QString ) ;
QSqlQueryModel *afficher_c_rech(int);
QChart* chart_bar();
QChart* chart_pie();
private :
    int cin ;
    QString nom , prenom  ;
     int tel ;
     QString  mail ,adresse;
};


#endif // CLIENTS_H
