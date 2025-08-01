#include "supprimermastereude.h"
#include "ui_supprimermastereude.h"
#include "database.h"
#include<QMessageBox>

supprimerMasterEude::supprimerMasterEude(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimerMasterEude)
{
    sup2=new Suppression();
    ui->setupUi(this);
    QObject::connect(ui->supprimerEtude,&QPushButton::clicked,this,[&](){
       supp();
       this->close();
    });

}

supprimerMasterEude::~supprimerMasterEude()
{
    delete ui;
}
void supprimerMasterEude::supp(){
    if(DatabaseConnection::DBconnect()){
         QString codeapo=ui->supp->text();
        QSqlQuery query;
        query.exec("DELETE FROM master WHERE codeapo='"+codeapo+"'");
        if(query.next()){
            QMessageBox::information(this, "information", "L'etudiant a été supprimée");
            sup2->show();
        }
        DatabaseConnection::closeDB();
    }else{
        qWarning() << "Impossible de se connecter à la base de données.";
    }
}

