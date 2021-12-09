#ifndef CLIENTS_H
#define CLIENTS_H
#include<QString>
#include <QDialog>
#include <QMainWindow>
#include<QSqlDatabase>
#include <QSqlQueryModel>

class clients
{
public:
    clients();
    clients(int,QString,QString,int,QString,QString);
    int getCIN();
     QString getnom();
    QString getprenom();
      int gettel();
    QString getmail();
    QString getadresse();


    void setCIN(int);
    void setnom(QString);
    void setprenom(QString);
    void setmail(QString);
    void setadresse(QString);
    void settel(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(const QString &aux);
    bool supprimer(int);
     bool update(int , QString ,QString ,int ,QString, QString );


private:

int CIN,tel;
QString nom ,prenom ,mail,adresse;
};

#endif // CLIENTS_H
