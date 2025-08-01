#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class DatabaseConnection{
public:
static bool DBconnect(){

    //if(!QSqlDatabase::contains("qt_sql_default_connection")){
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

        db.setHostName("localhost");  // Adresse du serveur PostgreSQL
        db.setDatabaseName("DepartementGI");
        db.setUserName("postgres");
        db.setPassword("Sangareba1@");
        db.setPort(5433);

        // Ouvre la connexion à la base de données
        if (db.open()) {
            qDebug() << "Connexion à PostgreSQL établie avec succès";
            return true;

        } else {
            qWarning() << "Erreur de connexion à la base de données : " << db.lastError().text();
            return false;
        }

   // }
}

static void closeDB() {
   // QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");
    QSqlDatabase db = QSqlDatabase::database("QPSQL");
    db.close();
    qDebug() << "Connexion à la base de données fermée avec succès";
}
};




#endif // DATABASE_H
