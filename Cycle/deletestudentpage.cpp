#include "deletestudentpage.h"
#include "ui_deletestudentpage.h"
#include "database.h"

DeleteStudentPage::DeleteStudentPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteStudentPage)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,[&](){
        delete_stud();
        onBoutonClicked();
        this->close();
    });
}

void DeleteStudentPage::delete_stud(){
            if(!(ui->lineEdit->text().isEmpty())){
                int code = ui->lineEdit->text().toInt();
                if(DatabaseConnection::DBconnect()){
                    QSqlQuery query;
                    bool success = query.exec("DELETE FROM etudiant WHERE code_apogee = '" +QString::number(code)+"'");
                    if(success){
                        QMessageBox::information(this, "information", "L'etudiant a été supprimée");
                    } else{
                        QMessageBox::warning(this, "Avertissement", "Code non trouvé");
                    }
                    DatabaseConnection::closeDB();
                }else{
                    qWarning() << "Impossible de se connecter à la base de données.";
                }
            }
}

DeleteStudentPage::~DeleteStudentPage()
{
    delete ui;
}

