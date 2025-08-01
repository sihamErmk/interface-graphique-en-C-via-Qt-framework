#include "addprof.h"
#include "ui_addprof.h"
#include "database.h"

AddProf::AddProf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddProf)
{
    this->setFixedSize(500,600);
    ui->setupUi(this);
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,[&](){
        add();
        onBoutonClicked();
        clearLineEditFields();
        this->close();
    });
}

void AddProf::add(){
    if(!(ui->lineEdit->text()).isEmpty() && !(ui->lineEdit_2->text()).isEmpty() && !(ui->lineEdit_3->text()).isEmpty()){
        QString nom = ui->lineEdit->text();
        QString prenom = ui->lineEdit_2->text();
        QString charge_mod = ui->lineEdit_3->text();
        if(DatabaseConnection::DBconnect()){
            QSqlQuery query;
            QString insertQuery = QString("INSERT INTO professeur (nom_prof, prenom_prof, charge_mod) VALUES ('%1', '%2', '%3')")
                                      .arg(nom)
                                      .arg(prenom)
                                      .arg(charge_mod);
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

void AddProf::clearLineEditFields(){
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}

AddProf::~AddProf()
{
    delete ui;
}
