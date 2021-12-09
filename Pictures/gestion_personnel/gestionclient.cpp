#include "client.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>
#include <QDialog>
#include<QSqlQuery>
#include <QSystemTrayIcon>
#include "smtp.h"
#include "ui_mainwindow.h"
#include "excel.h"
#include <QIntValidator>
gestionclient::gestionclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestionclient)
{
    ui->setupUi(this);
    ui->tab_client->setModel(c.afficher());
        ui->comboBox->setModel(c.afficher());
        ui->tableView_email->setModel(c.afficher());
        ui->le_CINsupp->setValidator(new QIntValidator(0,99999999,this));
         ui->le_cin->setValidator(new QIntValidator(0,99999999,this));
         ui->le_tel->setValidator(new QIntValidator(0,99999999,this));

}

gestionclient::~gestionclient()
{
    delete ui;
}

void gestionclient::on_pb_ajouter12_clicked()
{
    int cin=ui->le_cin->text().toInt();

        QString nom=ui->le_nom->text();
        QString prenom=ui->le_prenom->text();
          int tel=ui->le_tel->text().toInt();
        QString mail=ui->le_mail->text();
         QString adresse=ui->le_adresse->text();

    Clients c (cin,nom,prenom,tel,mail,adresse);
    bool test=c.ajouter();
    if(test)

      { ui->tableView_email->setModel(c.afficher());
        ui->tab_client->setModel(c.afficher());
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                                             notifyIcon->show();
                                             notifyIcon->setIcon(QIcon("icone.png"));


        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
   }

void gestionclient::on_pb_supprimer_clicked()
{
    c.setcin(ui->le_CINsupp->text().toInt());
    bool test=c.supprimer(c.getcin());
    if (test)
    {ui->tableView_email->setModel(c.afficher());
        ui->tab_client->setModel(c.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                              QObject::tr("suppression effectue.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

          }

          else
          QMessageBox::critical(nullptr, QObject::tr("not ok"),
                          QObject::tr("suppression non effectuée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

}


void gestionclient::on_pushButton_3_clicked()

{
  ui->tab_client->setModel(c.afficher());

    int cin=ui->le_cin->text().toInt();
        QString nom=ui->le_nom->text();
        QString prenom=ui->le_prenom->text();
        int tel=ui->le_tel->text().toInt();
        QString mail=ui->le_mail->text();
         QString adresse=ui->le_adresse->text();

        bool    test=c.update(cin,nom,prenom,tel,mail,adresse);
        if (test)
              { ui->tab_client->setModel(c.afficher());

                  QMessageBox::information(nullptr,QObject::tr("OK"),
                                       QObject::tr("modification établie"),
                                       QMessageBox::Ok);}
              else{
              QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                      QObject::tr("modification non établie"),
                                      QMessageBox::Cancel);
            }

}




void gestionclient::on_comboBox_activated(const QString &arg1)
{
    int cin = ui->comboBox->currentText().toInt();
         QString id_string= QString::number(cin);
                QSqlQuery query;
                query.prepare("select * from GESTIONCLIENT where CIN ='"+id_string+"'");

                if(query.exec()){

                    while(query.next())
                    {

                   ui->le_cin->setText(query.value(0).toString());
                   ui->le_nom->setText(query.value(1).toString());
                    ui->le_prenom->setText(query.value(2).toString());
                    ui->le_tel->setText(query.value(3).toString());
                    ui->le_mail->setText(query.value(4).toString());
                    ui->le_adresse->setText(query.value(5).toString());


    }}
                else
                    QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

    }


void gestionclient::on_tri_parcin_clicked()
{
    {QMessageBox msgBox ;
                QSqlQueryModel * model= new QSqlQueryModel();


                   model->setQuery("select * from GESTIONCLIENT order by cin");

                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                  model->setHeaderData(2, Qt::Horizontal, QObject::tr(" prenom"));
                  model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
                   model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
                    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));

                            ui->tab_client->setModel(model);
                            ui->tab_client->show();
                            msgBox.setText("Tri avec succés.");
                            msgBox.exec();

            }
}

void gestionclient::on_tri_parnom_clicked()
{
    {
        QMessageBox msgBox ;
               QSqlQueryModel * model= new QSqlQueryModel();


                  model->setQuery("select * from GESTIONCLIENT order by nom ");

                  model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
                  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr(" prenom"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
                  model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
                   model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));


                           ui->tab_client->setModel(model);
                           ui->tab_client->show();
                           msgBox.setText("Tri avec succés.");
                           msgBox.exec();
     }
}


void gestionclient::on_tri_parprenom_clicked()
{
    QMessageBox msgBox ;
            QSqlQueryModel * model= new QSqlQueryModel();



               model->setQuery("select * from GESTIONCLIENT order by prenom");

               model->setHeaderData(0, Qt::Horizontal ,QObject::tr("cin"));
               model->setHeaderData(1, Qt::Horizontal ,QObject::tr("nom"));
              model->setHeaderData(2, Qt::Horizontal  ,QObject::tr(" prenom"));
              model->setHeaderData(3, Qt::Horizontal  ,QObject::tr("tel"));
               model->setHeaderData(4, Qt::Horizontal ,QObject::tr("mail"));
                model->setHeaderData(5, Qt::Horizontal,QObject::tr("adresse"));
                        ui->tab_client->setModel(model);
                        ui->tab_client->show();
                        msgBox.setText("Tri avec succés.");
                        msgBox.exec();
}



void gestionclient::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                                tr("Fichiers d'extension Excel (*.xls)"));
                if (fileName.isEmpty())
                    return;

                EXCEL obj(fileName, "test_bd", ui->tab_client);

                // you can change the column order and
                // choose which colum to export
                obj.addField(0, "cin", "char(20)");
                obj.addField(1, "nom", "char(20)");
                obj.addField(2, "prenom", "char(20)");
                obj.addField(3, "tel", "char(20)");
                obj.addField(4, "mail", "char(20)");
                 obj.addField(5, "adresse", "char(20)");


                int retVal = obj.export2Excel();

                if( retVal > 0)
                {
                    QMessageBox::information(this, tr("FAIS!"),
                                             QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                             );
                }
}

void gestionclient::on_pushButton_send_email_clicked()
{QString from = ui->lineEdit_from_email->text();
    QString to = ui->lineEdit_to_email->text();
    QString subject = ui->lineEdit_subject_email->text();
    QString password = ui->lineEdit_psswrd_email->text();
    QString email_text = ui->textEdit_email->toPlainText();

    Smtp* smtp = new Smtp(from, password);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(from, to, subject, email_text, files);
    else
        smtp->sendMail(from, to, subject, email_text);

}

void gestionclient::on_pushButton_browse_email_clicked()
{
files.clear();

QFileDialog dialog(this);
dialog.setDirectory(QDir::homePath());
dialog.setFileMode(QFileDialog::ExistingFiles);

if (dialog.exec())
    files = dialog.selectedFiles();

QString fileListString;
foreach(QString file, files)
    fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

ui->lineEdit_atchmnt_email->setText( fileListString );
}
void   gestionclient::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "email" ), tr( "Message sent.\n\n" ) );
    ui->lineEdit_to_email->clear();
    ui->lineEdit_subject_email->clear();
    ui->lineEdit_atchmnt_email->clear();
    ui->textEdit_email->clear();
    ui->lineEdit_psswrd_email->clear();
}

void gestionclient::on_cin_recherche_2_textChanged(const QString &arg1)
{
    Clients c;

            QString rech = ui->cin_recherche_2->text();
                c.recherche(ui->tab_client,rech);
                if (ui->cin_recherche_2->text().isEmpty())
                {
                    ui->tab_client->setModel(c.afficher());
                }
}

void gestionclient::on_pushButton_stat_clicked()
{
    QChart* chart_bar = c.chart_pie();
        QChartView* chart_view_bar = new QChartView(chart_bar, ui->label_stat );
        chart_view_bar->setRenderHint(QPainter::Antialiasing);
        chart_view_bar->setMinimumSize(400,400);
        chart_view_bar->show();
}
