#ifndef CLIENTS_H
#define CLIENTS_H


class clients
{
public:
    clients();
    clients(int,int,QString,QString,QString,QString)
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

private:
int CIN,tel;
QString nom ,prenom ,mail,adresse;
};


#endif // CLIENTS_H
