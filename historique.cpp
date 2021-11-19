#include "historique.h"
#include<QMessageBox>

Historique::Historique()
{
tmp="";
}
void Historique::save(QString nom,QString marque,QString fournisseur)
{    QFile file ("C:/Users/MSI/Desktop/QT/histo.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     out << nom+"\n"+marque << "\n" +fournisseur << "\n";


}
QString Historique::load()
{   tmp="";
    QFile file("C:/Users/MSI/Desktop/QT/histo.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {

         QString myString = in.readLine();
         tmp+=myString+"\n";

   }
   return tmp;
}
