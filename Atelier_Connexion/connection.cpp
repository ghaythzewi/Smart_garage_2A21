#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test.BD");
db.setUserName("emin105");//inserer nom de l'utilisateur
db.setPassword("zriba");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
