#include "ajoutermaster.h"
#include "ui_ajoutermaster.h"
#include "database.h"

ajouterMaster::ajouterMaster(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouterMaster)
{
    alerte3=new ALERTE();
    echec3=new Echec();
    this->setFixedSize(500,600);
    ui->setupUi(this);
    QObject::connect(ui->attmasterStudent,&QPushButton::clicked,this,[&](){
        //add();
       //onBoutonClicked();
         ajouterMasterR();
         this->close();
    });
}

ajouterMaster::~ajouterMaster()
{
    delete ui;
}

void ajouterMaster::ajouterMasterR(){
    QString nomprof =ui->input1->text();
    QString prenomprof =ui->input2->text();
    QString codeprof=ui->input3->text();
    QString lesmodules =ui->input4->text();
    if(DatabaseConnection::DBconnect()){
        QSqlQuery query;
        QString insertQuery = QString("INSERT INTO masterProf (nomprof,prenomprof,codeprof,lesmodules) VALUES ('%1', '%2', '%3', '%4')")
          .arg(nomprof)
          .arg(prenomprof)
          .arg(codeprof)
          .arg(lesmodules);
        query.exec(insertQuery);
        if (query.isActive()) {
            qDebug() << "Insertion réussie!";
            alerte3->show();
        } else {
            qDebug() << "Erreur lors de l'insertion:" << query.lastError().text();
            echec3->show();
        }
        DatabaseConnection::closeDB();
    }else{
        qWarning() << "Impossible de se connecter à la base de données.";
    }
}
