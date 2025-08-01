#include "addstudentpage.h"
#include "ui_addstudentpage.h"
#include "database.h"

AddStudentPage::AddStudentPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddStudentPage)
{
    this->setFixedSize(500,600);
    ui->setupUi(this);
    QObject::connect(ui->add,&QPushButton::clicked,this,[&](){
        add();
       onBoutonClicked();
        clearLineEditFields();
        this->close();
    });
}

void AddStudentPage::add(){
    if(!(ui->label->text()).isEmpty() && !(ui->label_2->text()).isEmpty() && !(ui->label_3->text()).isEmpty() && !(ui->label_4->text()).isEmpty()){
        QString nom = ui->nom->text();
        QString prenom = ui->prenom->text();
        QString sexe = ui->sexe->text();
        QString niveau = ui->niveau->text();
        if(DatabaseConnection::DBconnect()){
            QSqlQuery query;
            QString insertQuery = QString("INSERT INTO etudiant (nom_etu, prenom_etu, sexe, filiere) VALUES ('%1', '%2', '%3', '%4')")
              .arg(nom)
              .arg(prenom)
              .arg(sexe)
              .arg(niveau);
            query.exec(insertQuery);
            if (query.isActive()) {
                qDebug() << "Insertion réussie!";
            } else {
                qDebug() << "Erreur lors de l'insertion:" << query.lastError().text();
            }
            DatabaseConnection::closeDB();
        }else{
            qWarning() << "Impossible de se connecter à la base de données.";
        }

    }
}

void AddStudentPage::clearLineEditFields(){
    ui->nom->clear();
    ui->prenom->clear();
    ui->sexe->clear();
    ui->niveau->clear();
}

AddStudentPage::~AddStudentPage()
{
    delete ui;
}
