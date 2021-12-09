#include "gestionclient.h"
#include "ui_gestionclient.h"
#include "clients.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>
#include <QDialog>

gestionclient::gestionclient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionclient)
{

    ui->tab_clients->setModel(cl.afficher());
      ui->setupUi(this);


}

gestionclient::~gestionclient()
{
    delete ui;
}
void gestionclient::on_pb_ajouter_clicked()
{
    int CIN=ui->le_CIN->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int tel=ui->le_tel->text().toInt();
    QString mail=ui->le_mail->text();
     QString adresse=ui->le_adresse->text();


    clients cl(CIN,nom,prenom,tel,mail,adresse);
    bool test=cl.ajouter();

if (test)
{
    ui->tab_clients->setModel(cl.afficher());
    QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("ajout effectue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
    else  {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                            QObject::tr("erreur 404.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void gestionclient::on_pb_supprimerr_clicked()
{
    c1.setCIN(ui->le_CINsupp->text().toInt());
    bool test=c1.supprimer(c1.getCIN());
    if (test)
    {ui->tab_clients->setModel(c1.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                              QObject::tr("suppression effectue.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

          }

          else
          QMessageBox::critical(nullptr, QObject::tr("not ok"),
                          QObject::tr("suppression non effectuée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

}

void gestionclient::on_pb_modifier_clicked()
{

    ui->tab_clients->setModel(cl.afficher());
    int CIN=ui->le_CIN->text().toInt();
        QString nom=ui->le_nom->text();
        QString prenom=ui->le_prenom->text();
        int tel=ui->le_tel->text().toInt();
        QString mail=ui->le_mail->text();
         QString adresse=ui->le_adresse->text();
        bool    test=cl.update(CIN,nom,prenom,tel,mail,adresse);
        if (test)
              {
                      ui->tab_clients->setModel(cl.afficher());

                  QMessageBox::information(nullptr,QObject::tr("OK"),
                                       QObject::tr("modification établie"),
                                       QMessageBox::Ok);}
              else{
              QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                      QObject::tr("modification non établie"),
                                      QMessageBox::Cancel);
            }
}


