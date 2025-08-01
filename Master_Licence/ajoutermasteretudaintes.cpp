#include "ajoutermasteretudaintes.h"
#include "ui_ajoutermasteretudaintes.h"
#include "database.h"

ajouterMasterEtudaintes::ajouterMasterEtudaintes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouterMasterEtudaintes)
{
    alerte2=new ALERTE();
    echec2=new Echec();
    this->setFixedSize(500,600);
    ui->setupUi(this);
    QObject::connect(ui->attStudent,&QPushButton::clicked,this,[&](){
         addStudentsMaster();
         this->close();
    });
}

ajouterMasterEtudaintes::~ajouterMasterEtudaintes()
{
    delete ui;
}
void ajouterMasterEtudaintes::addStudentsMaster(){
    QString nom =ui->li1->text();
    QString prenom =ui->li2->text();
    int codeapo=ui->li3->text().toInt();
    QString filiere =ui->li4->text();
    QString date_ajout="CURRENT_TIMESTAMP";
    QString sexe=ui->lineS->text();
    if(DatabaseConnection::DBconnect()){
        QSqlQuery query;
        QString insertQuery = QString("INSERT INTO masterEtudiants(nom,prenom,codeapo , filiere,date_ajout,sexe) VALUES ('%1', '%2', %3, '%4',%5,'%6')")
          .arg(nom)
          .arg(prenom)
          .arg(codeapo)
          .arg(filiere)
           .arg(date_ajout)
                .arg(sexe);
        query.exec(insertQuery);
        if (query.isActive()) {
            qDebug() << "Insertion réussie!";
            alerte2->show();
        } else {
            qDebug() << "Erreur lors de l'insertion:" << query.lastError().text();
            echec2->show();
        }
        DatabaseConnection::closeDB();
    }else{
        qWarning() << "Impossible de se connecter à la base de données.";
    }
}
