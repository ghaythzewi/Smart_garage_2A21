#include "sponsor.h"


#include<QString>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QSqlQueryModel>
//#include<QPrintDialog>
 #include<QSystemTrayIcon>
#include<QMessageBox>
#include<QPdfWriter>
Sponsor::Sponsor()
{
    CIN=0;
    nom=" ";
    prenom=" ";
    tel=0;
}
Sponsor::Sponsor(QString nom,QString prenom,int CIN,int tel)
{
 this->nom=nom;
   this->prenom=prenom;
    this->CIN=CIN;
    this->tel=tel;


}

int Sponsor::getcin(){return CIN;}
int Sponsor::gettel(){return tel;}

QString Sponsor::getnom(){return nom;}
QString Sponsor::getprenom(){return prenom;}
void Sponsor::setcin(int CIN){this->CIN=CIN  ;}
void Sponsor::settel(int tel){this->tel=tel  ;}
void Sponsor::setnom(QString nom){this->nom=nom   ;}
void Sponsor::setprenom(QString prenom){this->prenom=prenom   ;}



bool Sponsor::ajouter()
{
    bool test=false;
    QSqlQuery query;

        QString CIN_string=QString::number(CIN);
        QString tel_string=QString::number(tel);

          query.prepare("INSERT INTO gocho (cin , nom , prenom , telephone) "
                        "VALUES (:CIN, :nom, :prenom ,:telephone  )");
          query.bindValue(0 , CIN_string);
          query.bindValue(1 , nom);
          query.bindValue(2 , prenom);
          query.bindValue(3,tel_string );

          query.exec();
    return test;
}


QSqlQueryModel * Sponsor::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from gocho");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("telephone"));

        return model;
}

bool Sponsor::modifierj(int cin ,QString nom , QString prenom ,int tel)
{
    QSqlQuery query;

    query.prepare("UPDATE gocho SET nom= :nom,prenom= :prenom , telephone= :tel  where cin= :cin ");
    query.bindValue(":cin", cin);
     query.bindValue(":nom",nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":telephone",tel);

            return    query.exec();
}

bool Sponsor:: supprimer(int id)
{

    QSqlQuery query;
    query.prepare("DELETE from gocho where cin = :id ");
    query.bindValue(":id",id);
    return    query.exec();

}

QSqlQueryModel* Sponsor::rechercher (const QString &aux)

{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("select * from gocho where ((cin || nom || prenom || telephone) LIKE '%"+aux+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));

   model->setHeaderData(6, Qt::Horizontal, QObject::tr("telephone"));

    return model;
}
void  Sponsor::genererPDF(){


                     QPdfWriter pdf("C:/Users/Administrateur/OneDrive/Documents/gocho/gocho.pdf");
                     QPainter painter(&pdf);

                    int i = 4000;
                         painter.setPen(Qt::red);
                         painter.setFont(QFont("Arial", 30));
                         painter.drawText(1100,1200,"Liste Des SPONSOR");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial", 15));
                        // painter.drawText(1100,2000,afficheDC);


                         painter.drawRect(100,100,7300,2600);
                         painter.drawRect(0,3000,9600,500);


                         painter.setFont(QFont("Arial", 9));
                         painter.drawText(200,3300,"CIN");
                         painter.drawText(1300,3300,"nom");
                         painter.drawText(2100,3300,"prenom");

                         QSqlQuery query;
                         query.prepare("select * from gocho");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(0).toString());
                             painter.drawText(1300,i,query.value(1).toString());
                             painter.drawText(2200,i,query.value(2).toString());
                             painter.drawText(3200,i,query.value(3).toString());

                            i = i + 500;
                         }


      int reponse = QMessageBox::Yes;
          if (reponse == QMessageBox::Yes)
          {
              QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
              notifyIcon->show();
            notifyIcon->setIcon(QIcon("icon.jpg"));

              notifyIcon->showMessage("GESTION DES  SPONSOR ","Liste sponsor pret dans PDF",QSystemTrayIcon::Information,15000);

              painter.end();
          }
          if (reponse == QMessageBox::No)
          {
               painter.end();
          }
}

