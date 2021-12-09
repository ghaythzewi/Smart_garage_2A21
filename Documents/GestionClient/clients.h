#ifndef CLIENTS_H
#define CLIENTS_H
#include<QString>
#include <QSqlQueryModel>

class clients
{
public:
    clients();
    clients(int,int,QString,QString,QString,QString);
    int getCIN();
    int gettel();
    QString getnom();
    QString getprenom();
    QString getmail();
    QString getadresse();
    void setCIN(int);
    void gettel(int);
    void setnom(QString);
    void setprenom(QString);
    void setmail(QString);
    void setadresse(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(const QString &aux);
    bool supprimer(int);


private:
int CIN,tel;
QString nom ,prenom ,mail,adresse;
};


#endif // CLIENTS_H
