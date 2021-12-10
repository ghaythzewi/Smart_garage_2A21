#include "historique.h"

#include<QMessageBox>

Historique::Historique()
{
tmp="";
}
void Historique::save(QString id,QString prenom,QString tel)
{    QFile file ("C:/Users/Administrateur/OneDrive/Documents/gocho/fiche.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     out << id+"\n"+prenom << "\n" +tel << "\n";


}

QString Historique::load()
{   tmp="";
    QFile file("C:/Users/Administrateur/OneDrive/Documents/gocho/fiche.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         qDebug()<<"erreur";
      tmp="";

    QTextStream in(&file);

  while (!in.atEnd()) {

         QString myString = in.readLine();
         tmp+=myString+"\n";

   }

   return tmp;
}

