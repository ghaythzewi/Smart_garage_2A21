#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
            QString password = ui->lineEdit_password->text();

            if(username ==  "ahmed" && password == "ahmed") {
                QMessageBox::information(this, "Login", "Username and password is correct");
            //    hide();
                nouveau = new MainWindow(this);
                 nouveau ->show();

            }
            else {
                QMessageBox::warning(this,"Login", "Username and password is not correct");
            }
}
