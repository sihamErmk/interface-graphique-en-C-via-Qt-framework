#include "supprimermasterprof.h"
#include "ui_supprimermasterprof.h"
#include "database.h"
#include <QMessageBox>
#include "suppression.h"

supprimerMasterProf::supprimerMasterProf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimerMasterProf)
{
    sup3=new Suppression();
    ui->setupUi(this);
    QObject::connect(ui->btnSupprimerMaster,&QPushButton::clicked,this,[&](){
       supprimerMaster();
       this->close();
    });

}
supprimerMasterProf::~supprimerMasterProf()
{
    delete ui;
}

void supprimerMasterProf::supprimerMaster(){
    if(DatabaseConnection::DBconnect()){
        QString codeProf=ui->SUPMAS->text();
        QSqlQuery query;
        query.exec("DELETE FROM masterProf WHERE codeProf='"+codeProf+"'");
        if(query.next()){
            QMessageBox::information(this, "information", "L'etudiant a été supprimée");
            sup3->show();
        }
        DatabaseConnection::closeDB();
    }else{
        qWarning() << "Impossible de se connecter à la base de données.";
    }


}
