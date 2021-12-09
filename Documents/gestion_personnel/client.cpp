
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>
#include <QObject>
#include <QSqlQuery>
#include <QString>
#include"mainwindow.h"
#include"client.h"


Client ::Client()
{ cin=0 ;
    nom="";
     prenom="";
     tel=0 ;
    mail="";
    adresse =" ";
}

 Client::Client(int cin ,QString nom ,QString prenom,int tel ,  QString mail ,QString adresse)
{this->cin=cin; this->nom=nom; this->prenom=prenom;
 this->tel=tel;this->mail=mail;this->adresse=adresse; }
 int Client::getcin () {return cin;}
QString Client::getnom() {return nom;}
QString Client:: getprenom() {return prenom;}
int Client::gettel () {return tel;}
QString Client::getmail() {return mail;}
 QString Client::getadresse(){return adresse;}
void Client::setcin(int cin){this->cin=cin;}
void Client ::setnom(QString nom){this->nom=nom;}
void Client::setprenom(QString prenom){this->prenom=prenom;}
void Client::settel(int tel){this->tel=tel;}
void Client::setmail(QString mail){this->mail=mail;}
 void Client::setadresse(QString adresse){this->adresse=adresse;}
bool Client ::ajouter()
{

   QSqlQuery query;
   QString cin_string=QString::number(cin);
    QString tel_string=QString::number(tel);
         query.prepare("INSERT INTO GESTIONCLIENT (cin, nom,prenom,tel,mail,adresse) "
                       "VALUES (:cin, :nom, :prenom, :tel, :mail, :adresse)");
         query.bindValue(0, cin_string);
         query.bindValue(1, nom);
         query.bindValue(2,prenom);
         query.bindValue(3,tel_string );
         query.bindValue(4, mail);
         query.bindValue(5, adresse);



         return  query.exec();



}
QSqlQueryModel * Client ::afficher(){



    QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT* FROM GESTIONCLIENT ");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
                  model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));


        return model;

}


bool Client ::supprimer(int cin)
{
 QSqlQuery query;
 QString res=QString::number(cin);
 query.prepare("delete from GESTIONCLIENT where cin=:cin");
 query.bindValue(":cin",res);
 return query.exec();
}
bool Client::update(int cin, QString nom, QString prenom, int tel, QString mail,QString adresse )

              {

                  QSqlQuery query;

                  QString cin_string=QString::number(cin);
                   QString tel_string=QString::number(tel);

                  query.prepare("UPDATE GESTIONCLIENT set cin=:cin,nom=:nom,prenom=:prenom,tel=:tel,mail=:mail,adresse=:adresse  where cin=:cin");

                  query.bindValue(":cin",cin_string);

                  query.bindValue(":nom",nom);

                  query.bindValue(":prenom",prenom);

                  query.bindValue(":tel",tel_string);

                  query.bindValue(":mail",mail);

                  query.bindValue(":adresse",adresse);


               return    query.exec();



              }

QSqlQueryModel *Client ::afficher_c_rech(int cin )
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString ::number(cin);
    model->setQuery("select * from GESTIONCLIENT where cin like '"+res+"%'");
    return model ;
}

void Client::recherche(QTableView * table, QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
;
        QSqlQuery *query=new QSqlQuery;
        query->prepare("select * from GESTIONCLIENT where nom like '%"+rech+"%' or cin like '%"+rech+"%' or prenom like '%"+rech+"%' ;");
        query->exec();
        model->setQuery(*query);
        table->setModel(model);
        table->show();
}
QChart* Client ::chart_bar()
{
    QSqlQuery q1,q2,q3,q4;
    qreal tot=0,c1=0,c2=0,c3=0;

    q1.prepare("SELECT * FROM CLIENTS");
    q1.exec();

    q2.prepare("SELECT * FROM CLIENTS WHERE tel>50000000 AND tel<60000000");
    q2.exec();

    q3.prepare("SELECT * FROM CLIENTS WHERE tel>20000000 AND tel<30000000");
    q3.exec();

    q4.prepare("SELECT * FROM CLIENTS WHERE tel>90000000 AND tel<100000000");
    q4.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}

    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;

//     Assign names to the set of bars used
    QBarSet *set0 = new QBarSet("num orange");
    QBarSet *set1 = new QBarSet("num ooreedoo");
    QBarSet *set2 = new QBarSet("num telecom");

//     Assign values for each bar
    *set0 << c1;
    *set1 << c2;
    *set2 << c3;

//     Add all sets of data to the chart as a whole
//     1. Bar Chart
    QBarSeries *series = new QBarSeries();

//     2. Stacked bar chart
    series->append(set0);
    series->append(set1);
    series->append(set2);

//     Used to define the bar chart to display, title, legend
    QChart *chart = new QChart();

//     Add the chart
    chart->addSeries(series);

//     Adds categories to the axes
//     QBarCategoryAxis *axis = new QBarCategoryAxis();

//     1. Bar chart
//     chart->setAxisX(axis, series);

//    // Used to change the palette
//    QPalette pal = qApp->palette();

//    // Change the color around the chart widget and text
//    pal.setColor(QPalette::Window, QRgb(0xffffff));
//    pal.setColor(QPalette::WindowText, QRgb(0x404044));

//     Apply palette changes to the application
//    qApp->setPalette(pal);

    return chart;
}

QChart* Client ::chart_pie()
{
    QSqlQuery q1,q2,q3,q4;
    qreal tot=0,c1=0,c2=0,c3=0;

    q1.prepare("SELECT * FROM GESTIONCLIENT");
    q1.exec();

    q2.prepare("SELECT * FROM GESTIONCLIENT WHERE tel>50000000 AND tel<60000000 ");
    q2.exec();

    q3.prepare("SELECT * FROM GESTIONCLIENT WHERE  tel>20000000 AND tel<30000000 ");
    q3.exec();

    q4.prepare("SELECT * FROM GESTIONCLIENT WHERE tel>90000000 AND tel<100000000 ");
    q4.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}

    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;

//     Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("num orange", c1);
    series->append("num ooreedoo", c2);
    series->append("num telecom", c3);
//     Create the chart widget
    QChart *chart = new QChart();

//     Add data to chart with title and show legend
    chart->addSeries(series);
    chart->legend()->show();

    return chart;

}
