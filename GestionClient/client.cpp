#include "client.h"
#include "ui_client.h"
#include "clients.h"
#include <QMessageBox>
#include <QDebug>
client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
}

client::~client()
{
    delete ui;
}

void client::on_pushButton_12_clicked()
{

}

void client::on_pb_ajouter_clicked()
{

}
