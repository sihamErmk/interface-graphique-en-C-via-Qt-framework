#include "addlicencestudent.h"
#include "ui_addlicencestudent.h"
#include "database.h"
#include "alerte.h"

addLicenceStudent::addLicenceStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addLicenceStudent)
{
    alerte1=new ALERTE;
    echec1=new Echec();
    this->setFixedSize(500,600);
    ui->setupUi(this);
    QObject::connect(ui->attStudent,&QPushButton::clicked,this,[&](){
        //add();
       //onBoutonClicked();
           AddLicenceStudent();
        clearLineEditFields();

       this->close();
    });
}

addLicenceStudent::~addLicenceStudent()
{
    delete ui;
}
void addLicenceStudent::AddLicenceStudent(){

    QString nom =ui->line1->text();
    QString prenom =ui->line2->text();
    //QString coapo=ui->line3->text();
    QString filiere =ui->line4->text();
    int codeapo=ui->line3->text().toInt();
    QString sexe=ui->line5->text();

    if(DatabaseConnection::DBconnect()){
        QSqlQuery query;
        QString insertQuery = QString("INSERT INTO licenceEtude (nom,prenom,codeapo,filiere,sexe) VALUES ('%1', '%2', %3, '%4','%5')")
          .arg(nom)
          .arg(prenom)
          .arg(codeapo)
          .arg(filiere)
                .arg(sexe);
        query.exec(insertQuery);
        if (query.isActive()) {
            qDebug() << "Insertion réussie!";
            alerte1->show();

        } else {
            qDebug() << "Erreur lors de l'insertion:" << query.lastError().text();
            echec1->show();
        }
        DatabaseConnection::closeDB();
    }else{
        qWarning() << "Impossible de se connecter à la base de données.";
    }
}
//clear line fields function
void addLicenceStudent::clearLineEditFields(){
    ui->line1->clear();
    ui->line2->clear();
    ui->line3->clear();
    ui->line4->clear();
}

void addLicenceStudent::on_pushButton_clicked()
{


}

