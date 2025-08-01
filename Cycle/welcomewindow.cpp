#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginpage.h"

WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WelcomeWindow)
{
    //this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(1080,806);
    //this->setStatusBar(nullptr);
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    msgbox = new QMessageBox;
    msgbox->setText("Veuillez vous connecter d'abord");
    msgbox->addButton("OK", QMessageBox::AcceptRole);
    msgbox->setIcon(QMessageBox::Critical);
    login = new LoginPage;
    addstudentpage = new AddStudentPage;
    addprofpage = new AddProf;
    deletestudentpage = new DeleteStudentPage;
    model = new QStandardItemModel(this);
    model_1 = new QStandardItemModel(this);
    model_2 = new QStandardItemModel(this);
    model_3 = new QStandardItemModel(this);
    model_4 = new QStandardItemModel(this);
    model_5 = new QStandardItemModel(this);
    model_6 = new QStandardItemModel(this);
    timer = new QTimer(this);
    ui->cyclebtn->setLayout(new QVBoxLayout);
    ui->cyclebtn->layout()->addWidget(ui->cycle_logo);
    ui->cyclebtn->layout()->addWidget(ui->label_8);
    ui->master_btn->setLayout(new QVBoxLayout);
    ui->master_btn->layout()->addWidget(ui->master_logo);
    ui->master_btn->layout()->addWidget(ui->label_10);
    ui->licence_btn->setLayout(new QVBoxLayout);
    ui->licence_btn->layout()->addWidget(ui->licence_logo);
    ui->licence_btn->layout()->addWidget(ui->label_12);
    ui->filterComboBox->addItem("Toutes");
    ui->filterComboBox->addItem("LSI I");
    ui->filterComboBox->addItem("LSI II");
    ui->filterComboBox->addItem("LSI III");
    ui->lineEdit_3->setPlaceholderText("Sujet");
    ui->lineEdit->setPlaceholderText("Nom de l'entreprise");
    ui->lineEdit_2->setPlaceholderText("Code Apogé de l'étudiant");
    ui->lineEdit_4->setPlaceholderText("Membre du jury");
    QVBoxLayout *contentLayout = new QVBoxLayout;

    // Ajouter des widgets au contenu (exemple avec des QLabel)
    ui->label_47->setFixedHeight(30);
    ui->label_80->setFixedHeight(30);
    ui->label_79->setFixedHeight(30);
    ui->label_76->setFixedHeight(450);
    ui->label_78->setFixedHeight(450);
    ui->label_77->setFixedHeight(450);
    contentLayout->addWidget(ui->label_47);
    contentLayout->addWidget(ui->label_76);
    contentLayout->addWidget(ui->label_80);
    contentLayout->addWidget(ui->label_78);
    contentLayout->addWidget(ui->label_79);
    contentLayout->addWidget(ui->label_77);
    ui->scrollAreaWidgetContents->setLayout(contentLayout);

    // Connecter le signal timeout du QTimer à la fonction de mise à jour
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(mettreAJourHeure()));

    // Définir l'intervalle du QTimer à 1000 ms (1 seconde)
    timer->start(1000);
    QObject::connect(ui->cyclebtn, &QPushButton::clicked, this, [&](){
        if(isUserConnected){
            ui->stackedWidget->setCurrentIndex(1);
            ui->cycle_stackedWidget->setCurrentIndex(0);
            loadLastStudentRecord();
            studentCount(0);
            studentCount(1);
            studentCount(2);
        } else {
            msgbox->exec();
        }

    });
    QObject::connect(ui->master_btn, &QPushButton::clicked, this,[&](){
        if(isUserConnected){
            WelcomeWindow::boutonClique();
        } else {
            msgbox->exec();
        }
    });
    QObject::connect(ui->licence_btn, &QPushButton::clicked, this, [&](){
        if(isUserConnected){
            WelcomeWindow::boutonClique();
        } else {
            msgbox->exec();
        }
    });
    QObject::connect(ui->login_btn, &QPushButton::clicked, login,[&](){
        login->show();
    });
    QObject::connect(ui->dashboardbtn, &QPushButton::clicked, this, [&](){
        ui->cycle_stackedWidget->setCurrentIndex(0);
        loadLastStudentRecord();
        studentCount(0);
        studentCount(1);
        studentCount(2);
    });
    QObject::connect(ui->profbtn, &QPushButton::clicked, this, [&](){
        ui->cycle_stackedWidget->setCurrentIndex(1);
        loadProfData();
    });
    QObject::connect(ui->studentbtn, &QPushButton::clicked, this, [&](){
        ui->cycle_stackedWidget->setCurrentIndex(2);
        loadStudentData();

    });
    QObject::connect(addprofpage, &AddProf::boutonClicked, this, [&](){
        loadProfData();

    });
    QObject::connect(ui->modulebtn, &QPushButton::clicked, this, [&](){
        ui->cycle_stackedWidget->setCurrentIndex(3);
        loadModS1Data();
        loadModS3Data();
    });
    QObject::connect(ui->enmploibtn, &QPushButton::clicked, this, [&](){
        ui->cycle_stackedWidget->setCurrentIndex(4);
    });
    QObject::connect(ui->sallebtn, &QPushButton::clicked, this, [&](){
        ui->cycle_stackedWidget->setCurrentIndex(5);
        loadSalleData();
    });
    QObject::connect(ui->soutenancebtn, &QPushButton::clicked, this, [&](){
        ui->cycle_stackedWidget->setCurrentIndex(6);
        loadSoutData();
    });

    QObject::connect(ui->decobtn, &QPushButton::clicked, this, [&](){
    QWidget *currentPage = ui->stackedWidget->currentWidget();

    // Fermez la fenêtre parente de la page actuelle (si elle existe)
    if (currentPage) {
        QMainWindow *mainWindow = qobject_cast<QMainWindow *>(currentPage->window());
        if (mainWindow) {
            mainWindow->close();
        }

     }
    });
    QObject::connect(ui->filterComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &WelcomeWindow::filtrer);
    QObject::connect(ui->student_addbtn, &QPushButton::clicked, addstudentpage,[&](){
        addstudentpage->show();
    });
    QObject::connect(addstudentpage,&AddStudentPage::boutonClicked,this,[&](){
        loadStudentData();
    });
    QObject::connect(deletestudentpage,&DeleteStudentPage::boutonClicked,this,[&]{
       loadStudentData();
    });
    QObject::connect(ui->student_deletebtn, &QPushButton::clicked, deletestudentpage,[&](){
        deletestudentpage->show();
    });
    QObject::connect(ui->add_prof_btn, &QPushButton::clicked, this, [&](){
        addprofpage->show();
    });
    QObject::connect(ui->sout_valid_btn, &QPushButton::clicked, this, [&]{
    saveSoutDetail();
    });
   /* QObject::connect(deletestudentpage,&DeleteStudentPage::boutonClicked,this,[&](){
        deleteStudent(codeTodelete);
        codeTodelete = -1;
    });*/

    QGraphicsDropShadowEffect *shadowEffect1 = new QGraphicsDropShadowEffect;
    shadowEffect1->setBlurRadius(10);
    shadowEffect1->setColor(QColor(0, 0, 0, 150)); // Couleur de l'ombre (R, G, B, alpha)
    shadowEffect1->setOffset(5, 5); // Décalage de l'ombre (x, y)
    ui->label_57->setGraphicsEffect(shadowEffect1);
    QGraphicsDropShadowEffect *shadowEffect2 = new QGraphicsDropShadowEffect;
    shadowEffect2->setBlurRadius(10);
    shadowEffect2->setColor(QColor(0, 0, 0, 150)); // Couleur de l'ombre (R, G, B, alpha)
    shadowEffect2->setOffset(5, 5); // Décalage de l'ombre (x, y)
    ui->label_58->setGraphicsEffect(shadowEffect2);
    QGraphicsDropShadowEffect *shadowEffect3 = new QGraphicsDropShadowEffect;
    shadowEffect3->setBlurRadius(10);
    shadowEffect3->setColor(QColor(0, 0, 0, 150)); // Couleur de l'ombre (R, G, B, alpha)
    shadowEffect3->setOffset(5, 5); // Décalage de l'ombre (x, y)
    ui->label_59->setGraphicsEffect(shadowEffect3);
    QGraphicsDropShadowEffect *shadowEffect4 = new QGraphicsDropShadowEffect;
    shadowEffect4->setBlurRadius(10);
    shadowEffect4->setColor(QColor(0, 0, 0, 150)); // Couleur de l'ombre (R, G, B, alpha)
    shadowEffect4->setOffset(5, 5); // Décalage de l'ombre (x, y)
    ui->label_60->setGraphicsEffect(shadowEffect4);
    QGraphicsDropShadowEffect *shadowEffect5 = new QGraphicsDropShadowEffect;
    shadowEffect5->setBlurRadius(10);
    shadowEffect5->setColor(QColor(0, 0, 0, 150)); // Couleur de l'ombre (R, G, B, alpha)
    shadowEffect5->setOffset(5, 5); // Décalage de l'ombre (x, y)
    ui->label_75->setGraphicsEffect(shadowEffect5);
    QGraphicsDropShadowEffect *shadowEffect6 = new QGraphicsDropShadowEffect;
    shadowEffect6->setBlurRadius(10);
    shadowEffect6->setColor(QColor(0, 0, 0, 150)); // Couleur de l'ombre (R, G, B, alpha)
    shadowEffect6->setOffset(5, 5); // Décalage de l'ombre (x, y)
    ui->label_81->setGraphicsEffect(shadowEffect6);

}

void WelcomeWindow::boutonClique() {
    // Code à exécuter lorsque le bouton est cliqué
    qDebug() << "Le bouton a été cliqué !";
}

void WelcomeWindow::loadStudentData(){
    if(DatabaseConnection::DBconnect()){
        QSqlQuery query;
        query.exec("SELECT * FROM etudiant");
        if(query.isActive()){
            int row = 0;
            while(query.next()){
                QString code_apogee = query.value("code_apogee").toString();
                QString nom = query.value("nom_etu").toString();
                QString prenom = query.value("prenom_etu").toString();
                QString filiere = query.value("filiere").toString();

                model->setItem(row, 0, new QStandardItem(code_apogee));
                model->setItem(row, 1, new QStandardItem(nom));
                model->setItem(row, 2, new QStandardItem(prenom));
                model->setItem(row, 3, new QStandardItem(filiere));
                row++;
            }
        }
        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                QStandardItem *item = model->item(row, col);
                if (item) {
                    // Rendre l'élément non modifiable
                    item->setEditable(false);
                    item->setSelectable(false);
                }
            }
        }
        //model->setTable("etudiant");
        //model->select();
        DatabaseConnection::closeDB();
        ui->filterComboBox->setCurrentIndex(0);
        filtrer();
        ui->student_tableView->setModel(model);
        ui->student_tableView->horizontalHeader()->setVisible(false);
        ui->student_tableView->verticalHeader()->setVisible(false);
        ui->student_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
        qWarning() << "Impossible de se connecter à la base de données.";
    }


}

void WelcomeWindow::filtrer(){
    QString selectedFiliere = ui->filterComboBox->currentText();
    for (int row = 0; row < model->rowCount(); ++row) {
        QStandardItem *filiereItem = model->item(row, 3);
        if (filiereItem) {
            bool showRow = (selectedFiliere == "Toutes") || (filiereItem->text() == selectedFiliere);
            ui->student_tableView->setRowHidden(row, !showRow);
        }
    }
}

void WelcomeWindow::mettreAJourHeure() {
    // Mettre à jour le QLabel avec la nouvelle heure
    ui->label_73->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm:ss"));
}



void WelcomeWindow::studentCount(int type){
    if(DatabaseConnection::DBconnect()){
        QSqlQuery query;
        QString nombreEnregistrements;
        switch (type) {
        case 0: {
            if (query.exec("SELECT COUNT(*) FROM etudiant")) {
                // Si la requête a réussi, récupérez le résultat
                if (query.next()) {
                    nombreEnregistrements = query.value(0).toString();

                } else {
                    qDebug() << "Aucun enregistrement trouvé.";
                }
            } else {
                // Si la requête a échoué, affichez l'erreur
                qDebug() << "Erreur de requête : " << query.lastError().text();
            }
                ui->total_etu->setText(nombreEnregistrements);
            }
            break;
        case 1: {
                if (query.exec("SELECT COUNT(*) FROM etudiant where sexe = 'M' ")) {
                // Si la requête a réussi, récupérez le résultat
                if (query.next()) {
                    nombreEnregistrements = query.value(0).toString();

                } else {
                    qDebug() << "Aucun enregistrement trouvé.";
                }
                } else {
                // Si la requête a échoué, affichez l'erreur
                qDebug() << "Erreur de requête : " << query.lastError().text();
                }
                ui->total_gar->setText(nombreEnregistrements);
        }
        break;
        case 2: {
                if (query.exec("SELECT COUNT(*) FROM etudiant WHERE sexe = 'F' ")) {
                // Si la requête a réussi, récupérez le résultat
                if (query.next()) {
                    nombreEnregistrements = query.value(0).toString();

                } else {
                    qDebug() << "Aucun enregistrement trouvé.";
                }
                } else {
                // Si la requête a échoué, affichez l'erreur
                qDebug() << "Erreur de requête : " << query.lastError().text();
                }
                ui->total_fille->setText(nombreEnregistrements);
        }
        break;
        default:
            break;
        }
        DatabaseConnection::closeDB();
    }else{
        qWarning() << "Impossible de se connecter à la base de données.";
    }
}

void WelcomeWindow::loadProfData(){
    if(DatabaseConnection::DBconnect()){
        QSqlQuery query;
        query.exec("SELECT * FROM professeur");
        if(query.isActive()){
            int row = 0;
            while(query.next()){
                QString code_prof = query.value("code_prof").toString();
                QString nom_prof = query.value("nom_prof").toString();
                QString prenom_prof = query.value("prenom_prof").toString();
                QString charge_mod = query.value("charge_mod").toString();

                model_1->setItem(row, 0, new QStandardItem(code_prof));
                model_1->setItem(row, 1, new QStandardItem(nom_prof));
                model_1->setItem(row, 2, new QStandardItem(prenom_prof));
                model_1->setItem(row, 3, new QStandardItem(charge_mod));
                row++;
            }
        }
        for (int row = 0; row < model_1->rowCount(); ++row) {
            for (int col = 0; col < model_1->columnCount(); ++col) {
                QStandardItem *item = model_1->item(row, col);
                if (item) {
                    // Rendre l'élément non modifiable
                    item->setEditable(false);
                    item->setSelectable(false);
                }
            }
        }
        //model->setTable("etudiant");
        //model->select();
        DatabaseConnection::closeDB();
        ui->prof_tableView->setModel(model_1);
        ui->prof_tableView->horizontalHeader()->setVisible(false);
        ui->prof_tableView->verticalHeader()->setVisible(false);
        ui->prof_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
        qWarning() << "Impossible de se connecter à la base de données.";
    }
}

void WelcomeWindow::loadLastStudentRecord(){
    if(DatabaseConnection::DBconnect()){
        QSqlQuery query;
        query.exec("SELECT * FROM etudiant ORDER BY date_ajout DESC LIMIT 10");
        if(query.isActive()){
            int row = 0;
            while(query.next()){
                QString code_apogee = query.value("code_apogee").toString();
                QString nom = query.value("nom_etu").toString();
                QString prenom = query.value("prenom_etu").toString();
                QString filiere = query.value("filiere").toString();

                model_2->setItem(row, 0, new QStandardItem(code_apogee));
                model_2->setItem(row, 1, new QStandardItem(nom));
                model_2->setItem(row, 2, new QStandardItem(prenom));
                model_2->setItem(row, 3, new QStandardItem(filiere));
                row++;
            }
        }
        for (int row = 0; row < model_2->rowCount(); ++row) {
            for (int col = 0; col < model_2->columnCount(); ++col) {
                QStandardItem *item = model_2->item(row, col);
                if (item) {
                    // Rendre l'élément non modifiable
                    item->setEditable(false);
                    item->setSelectable(false);
                }
            }
        }
        DatabaseConnection::closeDB();
        ui->dashboard_tableView->setModel(model_2);
        ui->dashboard_tableView->horizontalHeader()->setVisible(false);
        ui->dashboard_tableView->verticalHeader()->setVisible(false);
        ui->dashboard_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
        qWarning() << "Impossible de se connecter à la base de données.";
    }
}

void WelcomeWindow::saveSoutDetail(){
        if(!(ui->lineEdit->text()).isEmpty() && !(ui->lineEdit_2->text()).isEmpty() && !(ui->lineEdit_3->text()).isEmpty() && !(ui->lineEdit_4->text()).isEmpty()){
            QString code = ui->lineEdit_2->text().replace("'", "''");
            QString entreprise = ui->lineEdit->text().replace("'", "''");
            QString sujet = ui->lineEdit_3->text().replace("'", "''");
            QString jury = ui->lineEdit_4->text().replace("'", "''");
            QDateTime date_time = ui->dateTimeEdit->dateTime();
            if(DatabaseConnection::DBconnect()){
            QSqlQuery query;
            QString insertQuery = QString("INSERT INTO soutenance (code_apogee, nom_entreprise, sujet_sout, membre_jury, date_time) VALUES ('%1', '%2', '%3', '%4', '%5')")
                                      .arg(code)
                                      .arg(entreprise)
                                      .arg(sujet)
                                      .arg(jury)
                                      .arg(date_time.toString("dd-MM-yyyy HH:mm"));
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

void WelcomeWindow::loadSoutData(){
    if(DatabaseConnection::DBconnect()){
    QSqlQuery query;
    query.exec("SELECT soutenance.*, etudiant.filiere FROM soutenance INNER JOIN etudiant ON soutenance.code_apogee = etudiant.code_apogee");
    if(query.isActive()){
        int row = 0;
        while(query.next()){
            QString code = query.value("code_apogee").toString();
            QString filiere = query.value("etudiant.filiere").toString();
            QString entreprise = query.value("soutenance.nom_entreprise").toString();
            QString sujet = query.value("soutenance.sujet_sout").toString();
            QDateTime date = query.value("soutenance.date_time").toDateTime();
            QString statut = (date < QDateTime::currentDateTime())? "Effectué":"A Venir";
            model_3->setItem(row, 0, new QStandardItem(code));
            model_3->setItem(row, 1, new QStandardItem(filiere));
            model_3->setItem(row, 2, new QStandardItem(entreprise));
            model_3->setItem(row, 3, new QStandardItem(sujet));
            model_3->setItem(row, 4, new QStandardItem(date.toString("dd-MM-yyyy HH:mm")));
            model_3->setItem(row, 5, new QStandardItem(statut));
            row++;
        }
    }
    for (int row = 0; row < model_3->rowCount(); ++row) {
        for (int col = 0; col < model_3->columnCount(); ++col) {
            QStandardItem *item = model_3->item(row, col);
            if (item) {
                // Rendre l'élément non modifiable
                item->setEditable(false);
                item->setSelectable(false);
            }
        }
    }
    DatabaseConnection::closeDB();
    ui->sout_tableView->setModel(model_3);
    ui->sout_tableView->horizontalHeader()->setVisible(false);
    ui->sout_tableView->verticalHeader()->setVisible(false);
    ui->sout_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
    qWarning() << "Impossible de se connecter à la base de données.";
    }
}

void WelcomeWindow::loadModS3Data() {
    if(DatabaseConnection::DBconnect()) {
        QSqlQuery query;
        if (query.exec("SELECT module.code_mod, module.intitule, professeur.nom_prof, professeur.prenom_prof "
                       "FROM module "
                       "INNER JOIN professeur ON module.code_prof = professeur.code_prof "
                       "WHERE module.sem_mod = 'S3'")) {
            if(query.isActive()) {
                int row = 0;
                while(query.next()) {
                    QString code = query.value("code_mod").toString();
                    QString intitule = query.value("intitule").toString();
                    QString nom_prof = query.value("nom_prof").toString();
                    QString prenom_prof = query.value("prenom_prof").toString();
                    model_5->setItem(row, 0, new QStandardItem(code));
                    model_5->setItem(row, 1, new QStandardItem(intitule));
                    model_5->setItem(row, 2, new QStandardItem(nom_prof));
                    model_5->setItem(row, 3, new QStandardItem(prenom_prof));
                    row++;
                }
            } else {
                qDebug() << "La requête n'est pas active.";
            }
        } else {
            qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        }

        for (int row = 0; row < model_5->rowCount(); ++row) {
            for (int col = 0; col < model_5->columnCount(); ++col) {
                QStandardItem *item = model_5->item(row, col);
                if (item) {
                    // Rendre l'élément non modifiable
                    item->setEditable(false);
                    item->setSelectable(false);
                }
            }
        }

        DatabaseConnection::closeDB();
        ui->s3_mod_tableView->setModel(model_5);
        ui->s3_mod_tableView->horizontalHeader()->setVisible(false);
        ui->s3_mod_tableView->verticalHeader()->setVisible(false);
        ui->s3_mod_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
        qWarning() << "Impossible de se connecter à la base de données.";
    }
}


void WelcomeWindow::loadModS1Data() {
    if(DatabaseConnection::DBconnect()) {
        QSqlQuery query;
        if (query.exec("SELECT module.code_mod, module.intitule, professeur.nom_prof, professeur.prenom_prof "
                       "FROM module "
                       "INNER JOIN professeur ON module.code_prof = professeur.code_prof "
                       "WHERE module.sem_mod = 'S1'")) {
            if(query.isActive()) {
                int row = 0;
                while(query.next()) {
                    QString code = query.value("code_mod").toString();
                    QString intitule = query.value("intitule").toString();
                    QString nom_prof = query.value("nom_prof").toString();
                    QString prenom_prof = query.value("prenom_prof").toString();
                    model_4->setItem(row, 0, new QStandardItem(code));
                    model_4->setItem(row, 1, new QStandardItem(intitule));
                    model_4->setItem(row, 2, new QStandardItem(nom_prof));
                    model_4->setItem(row, 3, new QStandardItem(prenom_prof));
                    row++;
                }
            } else {
                qDebug() << "La requête n'est pas active.";
            }
        } else {
            qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        }

        for (int row = 0; row < model_4->rowCount(); ++row) {
            for (int col = 0; col < model_4->columnCount(); ++col) {
                QStandardItem *item = model_4->item(row, col);
                if (item) {
                    // Rendre l'élément non modifiable
                    item->setEditable(false);
                    item->setSelectable(false);
                }
            }
        }

        DatabaseConnection::closeDB();
        ui->s1_modtableView->setModel(model_4);
        ui->s1_modtableView->horizontalHeader()->setVisible(false);
        ui->s1_modtableView->verticalHeader()->setVisible(false);
        ui->s1_modtableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
        qWarning() << "Impossible de se connecter à la base de données.";
    }
}

void WelcomeWindow::loadSalleData(){
    if(DatabaseConnection::DBconnect()){
        QSqlQuery query;
        query.exec("SELECT * FROM salle");
        if(query.isActive()){
            int row = 0;
            //int currentDayOfWeek = QDateTime::currentDateTime().date().dayOfWeek();
            while(query.next()){
                QString nom = query.value("nom_salle").toString();
                QString filiere;
                if(nom == "E22")
                    filiere = "LSI I";
                else if(nom == "E21")
                    filiere = "LSI II";
                else
                    filiere = "LSI III";
                model_6->setItem(row, 0, new QStandardItem(nom));
                model_6->setItem(row, 1, new QStandardItem(filiere));
                //model_6->setItem(row, 2, new QStandardItem(disponible));
                row++;
            }
        }
        for (int row = 0; row < model_6->rowCount(); ++row) {
            for (int col = 0; col < model_6->columnCount(); ++col) {
                QStandardItem *item = model_6->item(row, col);
                if (item) {
                    // Rendre l'élément non modifiable
                    item->setEditable(false);
                    item->setSelectable(false);
                }
            }
        }
        DatabaseConnection::closeDB();
        ui->salle_tableView->setModel(model_6);
        ui->salle_tableView->horizontalHeader()->setVisible(false);
        ui->salle_tableView->verticalHeader()->setVisible(false);
        ui->salle_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
        qWarning() << "Impossible de se connecter à la base de données.";
    }
}




WelcomeWindow::~WelcomeWindow()
{
    delete ui;
    delete login;
    delete addstudentpage;
    delete deletestudentpage;
    delete msgbox;
    delete model;
    delete model_1;
    delete model_2;
    delete model_3;
    delete model_4;
    delete model_5;
    delete addprofpage;
}

