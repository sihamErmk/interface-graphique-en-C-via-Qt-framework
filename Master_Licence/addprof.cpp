#include "addprof.h"
#include "ui_addprof.h"
#include "database.h"
#include "alerte.h"


addProf::addProf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addProf)
{
    alerte4=new ALERTE();
    this->setFixedSize(500,600);
    ui->setupUi(this);
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,[&](){
        addProfs();
       this->close();
    });
}

//ajouter un professeur
void addProf::addProfs(){
    //////
    ///
    QString nomProf =ui->l1->text();
    QString prenomProf=ui->l2->text();
    QString codeProf =ui->l3->text();
    QString lesmodules =ui->l4->text();
    if(DatabaseConnection::DBconnect()){
        QSqlQuery query;
        QString insertQuery = QString("INSERT INTO profs (nomProf,prenomProf,codeProf , lesmodules) VALUES ('%1', '%2', '%3', '%4')")
          .arg(nomProf)
          .arg(prenomProf)
          .arg(codeProf)
          .arg(lesmodules);
        query.exec(insertQuery);
        if (query.isActive()) {
            qDebug() << "Insertion réussie!";
            alerte4->show();
        } else {
            qDebug() << "Erreur lors de l'insertion:" << query.lastError().text();
        }
        DatabaseConnection::closeDB();
    }else{
        qWarning() << "Impossible de se connecter à la base de données.";
    }


    ////
}
addProf::~addProf()
{
    delete ui;
}
