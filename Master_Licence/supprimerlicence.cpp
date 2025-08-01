#include "supprimerlicence.h"
#include "ui_supprimerlicence.h"
#include "database.h"
#include<QMessageBox>

supprimerLicence::supprimerLicence(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimerLicence)
{
    sup=new Suppression();
    ui->setupUi(this);

    QObject::connect(ui->btnSupprimer,&QPushButton::clicked,this,[&](){
        supprimerlicence();
        clearLineEditFields();
        this->close();
    });
}
//QObject::connect(ui->pushButton,&QPushButton::clicked,this,[&](){


void supprimerLicence::supprimerlicence(){

    if(DatabaseConnection::DBconnect()){
         QString codeapo=ui->supp->text();
        QSqlQuery query;
        query.exec("DELETE FROM licenceEtude WHERE codeapo='"+codeapo+"'");
        if(query.next()){
            QMessageBox::information(this, "information", "L'etudiant a été supprimée");
            sup->show();
        }
        DatabaseConnection::closeDB();
    }else{
        qWarning() << "Impossible de se connecter à la base de données.";
    }

}
void supprimerLicence::clearLineEditFields(){
    ui->supp->clear();
}

supprimerLicence::~supprimerLicence()
{
    delete ui;
}
