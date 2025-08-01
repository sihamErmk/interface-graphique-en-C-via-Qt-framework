#include "loginpage.h"
#include "ui_loginpage.h"
//#include "utils.h"

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    this->setFixedSize(500,600);
    ui->setupUi(this);
    ui->lineEdit_3->setFixedHeight(3);
    ui->lineEdit_4->setFixedHeight(3);
    ui->username->setPlaceholderText("Username");
    ui->password->setPlaceholderText("Password");
    ui->password->setEchoMode(QLineEdit::Password);
    msgbox = new QMessageBox();
    msgbox->setText("username ou mot de passe incorrect");
    msgbox->addButton("OK", QMessageBox::AcceptRole);
    msgbox->setIcon(QMessageBox::Information);
    QObject::connect(ui->pushButton, &QPushButton::clicked,this,[&](){
    QString username = ui->username->text();
    QString password = ui->password->text();

    if (username.isEmpty() || password.isEmpty()) {
        qDebug() << "Veuillez remplir tous les champs.";
        return;
    }

    if (DatabaseConnection::DBconnect()) {
        QSqlQuery query;

        query.exec("SELECT username, password FROM utilisateur WHERE username='" + username + "' AND password ='" + password + "' ");
        if (query.isActive()) {
            if (query.size() > 0) {
                isUserConnected = true;
                qDebug() << "Connecté avec succès.";
                this->close();
            } else {
                isUserConnected = false;
                msgbox->exec();
            }
        } else {
            qWarning() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        }

        DatabaseConnection::closeDB();
    } else {
        qWarning() << "Impossible de se connecter à la base de données.";
    }
}
    );
}

LoginPage::~LoginPage()
{
    delete ui;
    delete msgbox;
}

bool isUserConnected = false;
