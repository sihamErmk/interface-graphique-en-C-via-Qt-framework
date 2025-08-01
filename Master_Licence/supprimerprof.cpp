#include "supprimerprof.h"
#include "ui_supprimerprof.h"
#include "database.h"
#include<QMessageBox>
#include "suppression.h"

supprimerProf::supprimerProf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimerProf)
{
   sup5=new Suppression();
    ui->setupUi(this);
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,[&](){
       deleteProf();
       this->close();
    });

}
void supprimerProf::deleteProf(){
    if(DatabaseConnection::DBconnect()){
         QString codeProf=ui->profsub->text();
        QSqlQuery query;
        query.exec("DELETE FROM profs WHERE codeProf='"+codeProf+"'");
        sup5->show();
        if(query.next()){
            QMessageBox::information(this, "information", "L'etudiant a été supprimée");

        }
        DatabaseConnection::closeDB();
    }else{
        qWarning() << "Impossible de se connecter à la base de données.";
    }
}

supprimerProf::~supprimerProf()
{
    delete ui;
}
