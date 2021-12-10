#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("smartgarage");
db.setUserName("ibrahim");//inserer nom de l'utilisateur
db.setPassword("201JMT2311");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
