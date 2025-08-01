#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginpage.h"


WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WelcomeWindow)
{
    this->setFixedSize(1080,806);
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    msgbox = new QMessageBox;
    msgbox->setText("Veuillez vous connecter d'abord");
    msgbox->addButton("OK", QMessageBox::AcceptRole);
    msgbox->setIcon(QMessageBox::Critical);
    login = new LoginPage;
    addstudentpage = new AddStudentPage;
    deletestudentpage = new DeleteStudentPage;
    model = new QStandardItemModel(this);
    modelLicence = new QStandardItemModel(this);
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
     //licence partie
    soutenancemodel = new QStandardItemModel(this);
    modelSalle = new QStandardItemModel(this);
    dashModel = new QStandardItemModel(this);
     modelLicence = new QStandardItemModel(this);
     model6=new QStandardItemModel(this);
    modelProf=new  QStandardItemModel(this);
    supprimerlicenceEtudiant=new supprimerLicence();
    addlicencestudent=new addLicenceStudent();
    addprofrs =new addProf();
    supprimeProf =new supprimerProf();
    //master partie
    //les declarations

    modelMaster= new QStandardItemModel(this);
    ajouter=new ajouterMaster();
    ajouterEtud= new ajouterMasterEtudaintes();
    supProfMaster=new  supprimerMasterProf();
    model1=new QStandardItemModel(this);
    model2=new QStandardItemModel(this);
    model3=new QStandardItemModel(this);
    model4 = new QStandardItemModel(this);
    model5= new QStandardItemModel(this);
    dashModelMaster= new QStandardItemModel(this);
    supprimerEtudiantes =new supprimerMasterEude();

    QObject::connect(ui->cyclebtn, &QPushButton::clicked, this, [&](){
        ui->stackedWidget->setCurrentIndex(2);
        ui->cycle_stackedWidget->setCurrentIndex(0);
    });


    QObject::connect(ui->login_btn, &QPushButton::clicked, login,[&](){
        login->show();
    });
    QObject::connect(ui->dashboardbtn, &QPushButton::clicked, this, [&](){
        ui->cycle_stackedWidget->setCurrentIndex(0);
    });
    QObject::connect(ui->profbtn, &QPushButton::clicked, this, [&](){
        ui->cycle_stackedWidget->setCurrentIndex(1);
    });
    QObject::connect(ui->studentbtn, &QPushButton::clicked, this, [&](){
        ui->cycle_stackedWidget->setCurrentIndex(2);
        loadStudentData();

    });
    QObject::connect(ui->modulebtn, &QPushButton::clicked, this, [&](){
        ui->cycle_stackedWidget->setCurrentIndex(3);
    });
    QObject::connect(ui->enmploibtn, &QPushButton::clicked, this, [&](){
        ui->cycle_stackedWidget->setCurrentIndex(4);
    });
    QObject::connect(ui->sallebtn, &QPushButton::clicked, this, [&](){
        ui->cycle_stackedWidget->setCurrentIndex(5);
        loadSalles();
    });
    QObject::connect(ui->soutenancebtn, &QPushButton::clicked, this, [&](){
        ui->cycle_stackedWidget->setCurrentIndex(6);
        loadsoutenance();
    });
    QObject::connect(ui->decobtn, &QPushButton::clicked, this, &WelcomeWindow::boutonClique);
    QObject::connect(ui->filterComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &WelcomeWindow::filtrerParFiliere);
    QObject::connect(ui->student_addbtn, &QPushButton::clicked, addstudentpage,[&](){
        addstudentpage->show();
    });
    QObject::connect(addstudentpage,&AddStudentPage::boutonClicked,this,[&](){
        loadDataAndUpdateModel();
    });

    QObject::connect(ui->student_deletebtn, &QPushButton::clicked, deletestudentpage,[&](){
        deletestudentpage->show();
    });



    //Licence Part
    //quand on click sur Licence inforatique et technique :
    QObject::connect(ui->licence_btn, &QPushButton::clicked, this, [&](){
        ui->stackedWidget->setCurrentIndex(3);
        ui->stackedLicence->setCurrentIndex(0);
    });
    QObject::connect(ui->btnDash,&QPushButton::clicked, this,[&](){
         ui->stackedLicence->setCurrentIndex(0);
         mettreAJourHeure();
         loadLatStudents();
         countingStudents(0);
         countingStudents(1);
         countingStudents(2);
    });
    QObject::connect(ui->btnProf,&QPushButton::clicked, this,[&](){
        ui->stackedLicence->setCurrentIndex(1);
        loadProfs();
    });
    QObject::connect(ui->btnEtu,&QPushButton::clicked, this,[&](){
        ui->stackedLicence->setCurrentIndex(2);
        loadLicenceStudent();
    });
    QObject::connect(ui->btnModule,&QPushButton::clicked, this,[&](){
        ui->stackedLicence->setCurrentIndex(3);
        loadModels();
        loadApp();
    });
    QObject::connect(ui->btnEmploi,&QPushButton::clicked, this,[&](){
        ui->stackedLicence->setCurrentIndex(4);
    });
    QObject::connect(ui->btnSalle,&QPushButton::clicked, this,[&](){
        ui->stackedLicence->setCurrentIndex(5);
        loadSalles();
    });
    QObject::connect(ui->btnSous,&QPushButton::clicked, this,[&](){
        ui->stackedLicence->setCurrentIndex(6);
        loadsoutenance();
    });
    //ajouter un etudiant du licence
    QObject::connect(ui->addBtn,&QPushButton::clicked,this,[&](){
        addlicencestudent->show();
    });
    //supprimer un etudiant du licence
    QObject::connect(ui->supBtn,&QPushButton::clicked,this,[&](){
        supprimerlicenceEtudiant->show();
    });
    //ajouter un professeur qui enseigne les licences
    QObject::connect(ui->pushButtonprf,&QPushButton::clicked,this,[&](){
        addprofrs->show();
    });
    //Supprimer un professeur licence
    QObject::connect(ui->subProf,&QPushButton::clicked,this,[&](){
        supprimeProf->show();
    });
    //ajouter une soutenance licence
    QObject::connect(ui->sout_valid_btn, &QPushButton::clicked, this, [&]{
         savesoutenance();
    });
    //quand on click sur deconnexion on sort du programme
    QObject::connect(ui->btnDec, &QPushButton::clicked, this, [&](){
        QWidget *currentPage = ui->stackedWidget->currentWidget();

        // Fermez la fenêtre parente de la page actuelle (si elle existe)
        if (currentPage) {
            QMainWindow *mainWindow = qobject_cast<QMainWindow *>(currentPage->window());
            if (mainWindow) {
                mainWindow->close();
            }
         }
     });
    //FiliereLicence()
    //la fonction utilusee pour filtrer les etudaints de la licence
    QObject::connect(ui->pushfiltre_2, &QPushButton::clicked, this, [&]{
         FiliereLicence();
    });
    //Master Part
    //quand on click sur master section
    QObject::connect(ui->master_btn, &QPushButton::clicked, this,[&](){
        ui->stackedWidget->setCurrentIndex(4);
        ui->stackedMaster->setCurrentIndex(0);
    });

    QObject::connect(ui->dashMaster, &QPushButton::clicked, this, [&](){
        ui->stackedMaster->setCurrentIndex(0);
        //chargerMaster();
        loadLastMasters();
        CountMaster(0);
        CountMaster(1);
        CountMaster(2);
    });
    QObject::connect(ui->dashMaster_2, &QPushButton::clicked, this, [&](){
        ui->stackedMaster->setCurrentIndex(1);
        afficherProfs();

    });

    QObject::connect(ui->EtudiantMastrer, &QPushButton::clicked, this, [&](){
        ui->stackedMaster->setCurrentIndex(2);
        chargerMaster();
    });
    QObject::connect(ui->ModuleMaster, &QPushButton::clicked, this, [&](){
        ui->stackedMaster->setCurrentIndex(3);
        ModelsAI();
        ModelsIT();
    });
    QObject::connect(ui->emploiMaster, &QPushButton::clicked, this, [&](){
        ui->stackedMaster->setCurrentIndex(4);
    });
    QObject::connect(ui->salleMaster, &QPushButton::clicked, this, [&](){
        ui->stackedMaster->setCurrentIndex(5);
        loadSalles1();
;    });
    QObject::connect(ui->SoutMaster, &QPushButton::clicked, this, [&](){
        ui->stackedMaster->setCurrentIndex(6);
        chargerSout();
    });
    QObject::connect(ui->decoMaster, &QPushButton::clicked, this, [&](){
        QWidget *currentPage = ui->stackedWidget->currentWidget();

        // Fermez la fenêtre parente de la page actuelle (si elle existe)
        if (currentPage) {
            QMainWindow *mainWindow = qobject_cast<QMainWindow *>(currentPage->window());
            if (mainWindow) {
                mainWindow->close();
            }

         }
    });
    //ajouter  addlicencestudent->show();
    QObject::connect(ui->ajouterMasterProf, &QPushButton::clicked, this, [&](){
        ajouter->show();
    });
    // supprimer un professeur :supProfMaster
    QObject::connect(ui->subProf_2, &QPushButton::clicked, this, [&](){
        supProfMaster->show();
    });
    //ajouter un etudaint du cycle master ajouterEtud
    QObject::connect(ui->addBtn_4, &QPushButton::clicked, this, [&](){
        ajouterEtud->show();
    });
    //supprimer etudiant supprimerEtudiantes
    QObject::connect(ui->supBtn_2, &QPushButton::clicked, this, [&](){
        supprimerEtudiantes->show();
    });
    //ajouter une soutenance des masters ajouterSouMaster() pushfiltre
    QObject::connect(ui->sout_valid_btn_3, &QPushButton::clicked, this, [&](){
        ajouterSouMaster();
    });
    QObject::connect(ui->pushfiltre, &QPushButton::clicked, this, [&](){
        FiliereFiltre();
    });



}

void WelcomeWindow::boutonClique() {
    // Code à exécuter lorsque le bouton est cliqué
    qDebug() << "Le bouton a été cliqué !";
}
//filtrer les etudiants selon filiere
void WelcomeWindow::filtrer(){

    
}
//
void WelcomeWindow::loadStudentData(){
    if(DatabaseConnection::DBconnect()){
        QSqlQuery query;
        query.exec("SELECT * FROM etudiant");
        if(query.isActive()){
            int row = 0;
            while(query.next()){
                QString code_apogee = query.value("code_apogee").toString();
                QString nom = query.value("nom").toString();
                QString prenom = query.value("prenom").toString();
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
        filtrerParFiliere();
        ui->student_tableView->setModel(model);
        ui->student_tableView->horizontalHeader()->setVisible(false);
        ui->student_tableView->verticalHeader()->setVisible(false);
        ui->student_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
       // qWarning() << "Impossible de se connecter à la base de données.";
    }


}
//load soutenance des licences
void WelcomeWindow::loadsoutenance(){
    //select soutenances.*,students.filiere FROM soutenances INNER JOIN students on soutenances.codeapo=students.codeapo;
    if(DatabaseConnection::DBconnect()){
       QSqlQuery query;
       query.exec("select souteTable.*,licenceEtude .filiere FROM souteTable INNER JOIN licenceEtude  on souteTable.codeapo=licenceEtude.codeapo");
       if(query.isActive()){
           int row = 0;
           while(query.next()){
               QString codeapo = query.value("codeapo").toString();
               QString filiere = query.value("licenceEtude .filiere").toString();
               QString entreprise = query.value("souteTable.entreprise").toString();
               QString sujet = query.value("souteTable.sujet").toString();
               QDateTime date = query.value("souteTable.dateheure").toDateTime();
               QString statut = query.value("souteTable.statut").toString();
               soutenancemodel->setItem(row, 0, new QStandardItem(codeapo));
               soutenancemodel->setItem(row, 1, new QStandardItem(filiere));
               soutenancemodel->setItem(row, 2, new QStandardItem(entreprise));
               soutenancemodel->setItem(row, 3, new QStandardItem(sujet));
               soutenancemodel->setItem(row, 4, new QStandardItem(date.toString("dd-MM-yyyy HH:mm")));
               soutenancemodel->setItem(row, 5, new QStandardItem(statut));
               row++;
           }
       }
       for (int row = 0; row < soutenancemodel->rowCount(); ++row) {
           for (int col = 0; col < soutenancemodel->columnCount(); ++col) {
               QStandardItem *item = soutenancemodel->item(row, col);
               if (item) {
                   // Rendre l'élément non modifiable
                   item->setEditable(false);
                   item->setSelectable(false);
               }
           }
       }
       DatabaseConnection::closeDB();
       ui->view->setModel(soutenancemodel);
       ui->view->horizontalHeader()->setVisible(false);
       ui->view->verticalHeader()->setVisible(false);
       ui->view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       } else {
       qWarning() << "Impossible de se connecter à la base de données.";
       }


}
//actualiser heure dans dashboard
void WelcomeWindow::mettreAJourHeure() {
    // Mettre à jour le QLabel avec la nouvelle heure
    ui->dateAndHeure->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm:ss"));
}
//ajouter soutenance
void WelcomeWindow::savesoutenance(){
                QString entreprise = ui->entreprise->text();
                QString codeapo = ui->cne->text();
                QDateTime date_time = ui->date->dateTime();
                QString jury = ui->members->text();
                QString sujet = ui->sujet->text();

                QString pasval="A VENIR";

                if(DatabaseConnection::DBconnect()){
                QSqlQuery query;
                query.prepare("insert into souteTable(codeapo,entreprise,sujet,dateheure,statut,membreJury) VALUES ('"+codeapo+"','"+entreprise+"','"+sujet+"','"+date_time.toString("dd-MM-yyyy HH:mm")+"','"+pasval+"','"+jury+"')");
                //query.exec(insertQuery);
                if (query.exec()) {
                    qDebug() << "Insertion réussie!";
                } else {
                    qDebug() << "Erreur lors de l'insertion:" << query.lastError().text();
                }
                DatabaseConnection::closeDB();
                }else{
                qWarning() << "Impossible de se connecter à la base de données.";
                }
}
//load les salles
void WelcomeWindow::loadSalles(){
    if(DatabaseConnection::DBconnect()){
        QSqlQuery query;
        query.exec("select *from salle");
        if(query.isActive()){
            int row = 0;
            while(query.next()){
                QString numbersalle = query.value("numbersalle").toString();
                QString affecta = query.value("affecta").toString();
                QString moduleen = query.value("moduleen").toString();
                QString heure = query.value("heure").toString();

                modelSalle->setItem(row, 0, new QStandardItem(numbersalle));
                modelSalle->setItem(row, 1, new QStandardItem(affecta));
                modelSalle->setItem(row, 3, new QStandardItem(moduleen));
                modelSalle->setItem(row, 2, new QStandardItem(heure));
                row++;
            }

        }
        for (int row = 0; row < modelLicence->rowCount(); ++row) {
            for (int col = 0; col < modelLicence->columnCount(); ++col) {
                QStandardItem *item = modelLicence->item(row, col);
                if (item) {
                    // Rendre l'élément non modifiable
                   // item->setEditable(false);
                   // item->setSelectable(false);
                }
            }
        }
        //model->setTable("etudiant");
        //model->select();
        DatabaseConnection::closeDB();
        ui->salleview->setModel(modelSalle);
        ui->salleview->horizontalHeader()->setVisible(false);
        ui->salleview->verticalHeader()->setVisible(false);
        ui->salleview->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
        qWarning() << "Impossible de se connecter à la base de données.";
    }

}
//la fonction pour charger les profs Licence
void  WelcomeWindow::loadProfs(){
    if(DatabaseConnection::DBconnect()){
        QSqlQuery myqry;
        myqry.exec("select *from profs");
        if(myqry.isActive()){
            int row=0;
            while(myqry.next()){
                QString nomProf=myqry.value("nomProf").toString();
                QString prenomProf=myqry.value("prenomProf").toString();
                QString codeProf=myqry.value("codeProf").toString();
                QString lesmodules=myqry.value("lesmodules").toString();

                modelProf->setItem(row,0,new QStandardItem(nomProf));
                modelProf->setItem(row,1,new QStandardItem(prenomProf));
                modelProf->setItem(row,2,new QStandardItem(codeProf));
                modelProf->setItem(row,3,new QStandardItem(lesmodules));
                row++;
            }
        }
        DatabaseConnection::closeDB();
        ui->tableViewProf->setModel(modelProf);
        ui->tableViewProf->horizontalHeader()->setVisible(false);
        ui->tableViewProf->verticalHeader()->setVisible(false);
        ui->tableViewProf->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
        qWarning() << "Impossible de se connecter à la base de données.";
    }

    }
//la fonction pour charger les donnees des etudiants licence

void WelcomeWindow::loadLicenceStudent(){
    if(DatabaseConnection::DBconnect()){
        QSqlQuery query;
        query.exec("SELECT *FROM licenceEtude ");
        if(query.isActive()){
            int row = 0;
            while(query.next()){
                QString nom = query.value("nom").toString();
                QString prenom = query.value("prenom").toString();
                QString filiere = query.value("filiere").toString();
                QString codeapo = query.value("codeapo").toString();

                modelLicence->setItem(row, 0, new QStandardItem(nom));
                modelLicence->setItem(row, 1, new QStandardItem(prenom));
                modelLicence->setItem(row, 3, new QStandardItem(filiere));
                modelLicence->setItem(row, 2, new QStandardItem(codeapo));
                row++;
            }

        }
        for (int row = 0; row < modelLicence->rowCount(); ++row) {
            for (int col = 0; col < modelLicence->columnCount(); ++col) {
                QStandardItem *item = modelLicence->item(row, col);
                if (item) {
                    // Rendre l'élément non modifiable
                   // item->setEditable(false);
                   // item->setSelectable(false);
                }
            }
        }
        //model->setTable("etudiant");
        //model->select();
        DatabaseConnection::closeDB();
        ui->tableView->setModel(modelLicence);
        ui->tableView->horizontalHeader()->setVisible(false);
        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
        qWarning() << "Impossible de se connecter à la base de données.";
    }
}


void WelcomeWindow::loadDataAndUpdateModel() {
    if (DatabaseConnection::DBconnect()) {
        // Chargez les données depuis la base de données
        QSqlQuery query;
        query.exec("SELECT * FROM etudiant");
        if (query.isActive()) {
            int row = 0;
            while (query.next()) {
                QString code_apogee = query.value("code_apogee").toString();
                QString nom = query.value("nom").toString();
                QString prenom = query.value("prenom").toString();
                QString filiere = query.value("filiere").toString();

                model->setItem(row, 0, new QStandardItem(code_apogee));
                model->setItem(row, 1, new QStandardItem(nom));
                model->setItem(row, 2, new QStandardItem(prenom));
                model->setItem(row, 3, new QStandardItem(filiere));
                row++;
            }
        }
        // Fermez la connexion à la base de données
        DatabaseConnection::closeDB();

        // Mettez à jour le modèle du QTableView
        ui->student_tableView->setModel(model);
    } else {
        qWarning() << "Impossible de se connecter à la base de données.";
    }
}

void WelcomeWindow::filtrerParFiliere(){
    QString selectedFiliere = ui->filterComboBox->currentText();
    for (int row = 0; row < model->rowCount(); ++row) {
        QStandardItem *filiereItem = model->item(row, 3);
        if (filiereItem) {
            bool showRow = (selectedFiliere == "Toutes") || (filiereItem->text() == selectedFiliere);
            ui->student_tableView->setRowHidden(row, !showRow);
        }
    }
}
//la fonction filtrer pour licence

//charger le donnees sur les modules
void WelcomeWindow::loadApp(){
     if(DatabaseConnection::DBconnect()){
         QSqlQuery query;
         query.exec("select *from infoModule");
         if(query.isActive()){
             while(query.next()){
                 QString indice= query.value("ad").toString();
                 QString intitule= query.value("intitule").toString();
                 QString nbrchap= query.value("nbrchap").toString();
                 QString heure= query.value("heure").toString();
                 if(indice=='1'){
                    ui->int1->setText(intitule);
                    ui->h1->setText(heure);
                    ui->chap1->setText(nbrchap);
                 }
                 if(indice=='2'){
                    ui->int2->setText(intitule);
                    ui->h2->setText(heure);
                    ui->chap2->setText(nbrchap);
                 }
                 if(indice=='3'){
                    ui->int3->setText(intitule);
                    ui->h3->setText(heure);
                    ui->chap3->setText(nbrchap);
                 }
                 if(indice=='4'){
                    ui->int4->setText(intitule);
                    ui->h4->setText(heure);
                    ui->chap4->setText(nbrchap);
                 }
                 if(indice=='5'){
                    ui->int5->setText(intitule);
                    ui->h5->setText(heure);
                    ui->cha5->setText(nbrchap);
                 }
                 if(indice=='6'){
                    ui->int1->setText(intitule);
                    ui->h1->setText(heure);
                    ui->chap6->setText(nbrchap);
                 }
             }
         }
     }
}
//charger les modules a partir du base donnees
void WelcomeWindow::loadModels(){
    if(DatabaseConnection::DBconnect()){

        QSqlQuery query;
        query.exec("select *from moduleInfo");
        if(query.isActive()){
            while(query.next()){
                QString indice= query.value("idd").toString();
                QString intitulemodule= query.value("intitulemodule").toString();
                QString heure= query.value("heure").toString();
                QString nbrchap= query.value("nbrchap").toString();
                if(indice=='1'){
                    ui->HEURElLABEL->setText(heure);
                    ui->module1->setText(intitulemodule);
                    ui->nbrChap->setText(nbrchap);
                }
                if(indice=='2'){
                    ui->heure2->setText(heure);
                    ui->module2->setText(intitulemodule);
                    ui->nbrChap_2->setText(nbrchap);
                }
                if(indice=='3'){
                    ui->heure3->setText(heure);
                    ui->module3->setText(intitulemodule);
                    ui->nbrChap_3->setText(nbrchap);
                }
                if(indice=='4'){
                    ui->heure4->setText(heure);
                    ui->module4->setText(intitulemodule);
                    ui->nbrChap_4->setText(nbrchap);
                }
                if(indice=='5'){
                    ui->heure5->setText(heure);
                    ui->module5->setText(intitulemodule);
                    ui->nbrChap_5->setText(nbrchap);
                }
                if(indice=='6'){
                    ui->heure6->setText(heure);
                    ui->module6->setText(intitulemodule);
                    ui->nbrChap_6->setText(nbrchap);
                }

            }
        }
    }
}
void WelcomeWindow::ModelsAI(){
    if(DatabaseConnection::DBconnect()){

        QSqlQuery query;
        query.exec("select *from ModuleAI");
        if(query.isActive()){
            while(query.next()){
                QString indice= query.value("idd").toString();
                QString intitulemodule= query.value("intitulemodule").toString();
                QString heure= query.value("heure").toString();
                QString nbrchap= query.value("nbrchap").toString();
                if(indice=='1'){
                    ui->HEURElLABEL_1->setText(heure);
                    ui->intitule1->setText(intitulemodule);
                    ui->nbrChap1->setText(nbrchap);
                }
                if(indice=='2'){
                    ui->HEURElLABEL_3->setText(heure);
                    ui->intitule2->setText(intitulemodule);
                    ui->nbrChap2->setText(nbrchap);
                }
                if(indice=='3'){
                    ui->HEURElLABEL_4->setText(heure);
                    ui->intitule3->setText(intitulemodule);
                    ui->nbrChap3->setText(nbrchap);
                }
                if(indice=='4'){
                    ui->HEURElLABEL_5->setText(heure);
                    ui->intitule4->setText(intitulemodule);
                    ui->nbrChap4->setText(nbrchap);
                }
                if(indice=='5'){
                    ui->HEURElLABEL_6->setText(heure);
                    ui->intitule5->setText(intitulemodule);
                    ui->nbrChap5->setText(nbrchap);
                }
                if(indice=='6'){
                    ui->HEURElLABEL_7->setText(heure);
                    ui->intitule6->setText(intitulemodule);
                    ui->nbrChap6->setText(nbrchap);
                }

            }
        }
    }
}
void WelcomeWindow::ModelsIT(){
    if(DatabaseConnection::DBconnect()){

        QSqlQuery query;
        query.exec("select *from ModuleIT");
        if(query.isActive()){
            while(query.next()){
                QString indice= query.value("idd").toString();
                QString intitulemodule= query.value("intitulemodule").toString();
                QString heure= query.value("heure").toString();
                QString nbrchap= query.value("nbrchap").toString();
                if(indice=='1'){
                    ui->HEURElLABEL_8->setText(heure);
                    ui->intitule7->setText(intitulemodule);
                    ui->nbrChap7->setText(nbrchap);
                }
                if(indice=='2'){
                    ui->HEURElLABEL_9->setText(heure);
                    ui->intitule8->setText(intitulemodule);
                    ui->nbrChap8->setText(nbrchap);
                }
                if(indice=='3'){
                    ui->HEURElLABEL_10->setText(heure);
                    ui->intitule9->setText(intitulemodule);
                    ui->nbrChap9->setText(nbrchap);
                }
                if(indice=='4'){
                    ui->HEURElLABEL_11->setText(heure);
                    ui->intitule101->setText(intitulemodule);
                    ui->nbrChap10->setText(nbrchap);
                }
                if(indice=='5'){
                    ui->HEURElLABEL_12->setText(heure);
                    ui->intitule11->setText(intitulemodule);
                    ui->nbrChap11->setText(nbrchap);
                }
                if(indice=='6'){
                    ui->HEURElLABEL_13->setText(heure);
                    ui->intitule12->setText(intitulemodule);
                    ui->nbrChap12->setText(nbrchap);
                }

            }
        }
    }

}
//la fonction pour charger les dernieres etudiants inscrits
void WelcomeWindow::loadLatStudents()
{

    if(DatabaseConnection::DBconnect()){
           QSqlQuery query;
           query.exec("SELECT * FROM licenceEtude ORDER BY date_ajout DESC LIMIT 10");
           if(query.isActive()){
               int row = 0;
               while(query.next()){
                   QString codeapo = query.value("codeapo").toString();
                   QString nom = query.value("nom").toString();
                   QString prenom = query.value("prenom").toString();
                   QString filiere = query.value("filiere").toString();

                   dashModel->setItem(row, 0, new QStandardItem(codeapo));
                   dashModel->setItem(row, 1, new QStandardItem(nom));
                   dashModel->setItem(row, 2, new QStandardItem(prenom));
                   dashModel->setItem(row, 3, new QStandardItem(filiere));
                   row++;
               }
           }
           for (int row = 0; row < dashModel->rowCount(); ++row) {
               for (int col = 0; col < dashModel->columnCount(); ++col) {
                   QStandardItem *item = dashModel->item(row, col);
                   if (item) {
                       // Rendre l'élément non modifiable
                       item->setEditable(false);
                       item->setSelectable(false);
                   }
               }
           }
           DatabaseConnection::closeDB();
           ui->tableDashView->setModel(dashModel);
           ui->tableDashView->horizontalHeader()->setVisible(false);
           ui->tableDashView->verticalHeader()->setVisible(false);
           ui->tableDashView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       } else {
           qWarning() << "Impossible de se connecter à la base de données.";
       }
}
//La fonction pour calculer totale des etudiants
void WelcomeWindow::countingStudents(int number){
    if(DatabaseConnection::DBconnect()){
            QSqlQuery query;
            QString nombreEnregistrements;
            switch (number) {
            case 0: {
                if (query.exec("SELECT COUNT(*) FROM licenceEtude ")) {
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
                    ui->globalStudents->setText(nombreEnregistrements);
                }
                break;
            case 1: {
                    if (query.exec("SELECT COUNT(*) FROM licenceEtude  where sexe = 'M' ")) {
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
                    ui->totGarcons->setText(nombreEnregistrements);
            }
            break;
            case 2: {
                    if (query.exec("SELECT COUNT(*) FROM licenceEtude  WHERE sexe = 'F' ")) {
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
                    ui->Tot_filles->setText(nombreEnregistrements);
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


//PARTIE MASTER
//la fonction pour charger les donnees des etudaints master
void WelcomeWindow::chargerMaster(){
    if(DatabaseConnection::DBconnect()){
        QSqlQuery query;
        query.exec("SELECT *FROM masterEtudiants");
        if(query.isActive()){
            int row = 0;
            while(query.next()){
                QString nom = query.value("nom").toString();
                QString prenom = query.value("prenom").toString();
                QString filiere = query.value("filiere").toString();
                QString codeapo = query.value("codeapo").toString();

                modelMaster->setItem(row, 0, new QStandardItem(nom));
                modelMaster->setItem(row, 1, new QStandardItem(prenom));
                modelMaster->setItem(row, 3, new QStandardItem(filiere));
                modelMaster->setItem(row, 2, new QStandardItem(codeapo));
                row++;
            }

        }
        for (int row = 0; row < modelLicence->rowCount(); ++row) {
            for (int col = 0; col < modelLicence->columnCount(); ++col) {
                QStandardItem *item = modelLicence->item(row, col);
                if (item) {

                }
            }
        }
        //model->setTable("etudiant");
        //model->select();
        DatabaseConnection::closeDB();
       // ui->filterComboBox_2->setCurrentIndex(0);
        //filtrerParLicenceType();
        ui->masterView_2->setModel(modelMaster);
        ui->masterView_2->horizontalHeader()->setVisible(false);
        ui->masterView_2->verticalHeader()->setVisible(false);
        ui->masterView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
        qWarning() << "Impossible de se connecter à la base de données.";
    }

}
//counting les etudiants du master
void WelcomeWindow::CountMaster(int number){
    if(DatabaseConnection::DBconnect()){
            QSqlQuery query;
            QString nombreEnregistrements;
            switch (number) {
            case 0: {
                if (query.exec("SELECT COUNT(*) FROM masterEtudiants")) {
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
                    ui->globalStudents_2->setText(nombreEnregistrements);
                }
                break;
            case 1: {
                    if (query.exec("SELECT COUNT(*) FROM masterEtudiants where sexe = 'M' ")) {
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
                    ui->totGarcons_2->setText(nombreEnregistrements);
            }
            break;
            case 2: {
                    if (query.exec("SELECT COUNT(*) FROM masterEtudiants WHERE sexe = 'F' ")) {
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
                    ui->Tot_filles_2->setText(nombreEnregistrements);
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
//charger les donnes des professeurs Master

//afficher les profs
void WelcomeWindow::afficherProfs(){
    if(DatabaseConnection::DBconnect()){
        QSqlQuery myqry;
        myqry.exec("select *from masterProf");
        if(myqry.isActive()){
            int row=0;
            while(myqry.next()){
                QString nomProf=myqry.value("nomprof").toString();
                QString prenomProf=myqry.value("prenomprof").toString();
                QString codeProf=myqry.value("codeprof").toString();
                QString lesmodules=myqry.value("lesmodules").toString();

                model2->setItem(row,0,new QStandardItem(nomProf));
                model2->setItem(row,1,new QStandardItem(prenomProf));
                model2->setItem(row,2,new QStandardItem(codeProf));
                model2->setItem(row,3,new QStandardItem(lesmodules));
                row++;
            }
        }
        DatabaseConnection::closeDB();
        ui->dashTableViewwww->setModel(model2);
        ui->dashTableViewwww->horizontalHeader()->setVisible(false);
        ui->dashTableViewwww->verticalHeader()->setVisible(false);
        ui->dashTableViewwww->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
        qWarning() << "Impossible de se connecter à la base de données.";
    }

}
//la fonction d'affichage pour dashboard
void WelcomeWindow::loadLastsMaster(){
    if(DatabaseConnection::DBconnect()){
           QSqlQuery query;
           query.exec("SELECT * FROM masterEtudiants ORDER BY date_ajout DESC LIMIT 10");
           if(query.isActive()){
               int row = 0;
               while(query.next()){
                   QString codeapo = query.value("codeapo").toString();
                   QString nom = query.value("nom").toString();
                   QString prenom = query.value("prenom").toString();
                   QString filiere = query.value("filiere").toString();

                   model1->setItem(row, 0, new QStandardItem(codeapo));
                   model1->setItem(row, 1, new QStandardItem(nom));
                   model1->setItem(row, 2, new QStandardItem(prenom));
                   model1->setItem(row, 3, new QStandardItem(filiere));
                   row++;
               }
           }
           for (int row = 0; row < dashModel->rowCount(); ++row) {
               for (int col = 0; col < dashModel->columnCount(); ++col) {
                   QStandardItem *item = dashModel->item(row, col);
                   if (item) {
                       // Rendre l'élément non modifiable
                       item->setEditable(false);
                       item->setSelectable(false);
                   }
               }
           }
           DatabaseConnection::closeDB();
          // ui->masterView->setModel(model1);
          // ui->masterView->horizontalHeader()->setVisible(false);
         //  ui->masterView->verticalHeader()->setVisible(false);
         //  ui->masterView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       } else {
           qWarning() << "Impossible de se connecter à la base de données.";
       }
}
// charger les soutenances du master :
void WelcomeWindow::chargerSout(){
    if(DatabaseConnection::DBconnect()){
       QSqlQuery query;
       query.exec("select *from soutenanceM");
       if(query.isActive()){
           int row = 0;
           while(query.next()){
               QString codeapo = query.value("codeapo").toString();
               QString entreprise = query.value("entreprise").toString();
               QString sujet = query.value("sujet").toString();
               QDateTime date = query.value("dateheure").toDateTime();
               QString statut = query.value("statut").toString();
               QString membreJury=query.value("membrejury").toString();
               model4->setItem(row, 0, new QStandardItem(codeapo));
               model4->setItem(row, 1, new QStandardItem(entreprise));
               model4->setItem(row, 2, new QStandardItem(sujet));
               model4->setItem(row, 3, new QStandardItem(date.toString("dd-MM-yyyy HH:mm")));
               model4->setItem(row, 4 ,new QStandardItem(membreJury));
               model4->setItem(row, 5, new QStandardItem(statut));
               row++;
           }
       }
       for (int row = 0; row < model4->rowCount(); ++row) {
           for (int col = 0; col < model4->columnCount(); ++col) {
               QStandardItem *item = model4->item(row, col);
               if (item) {
                   // Rendre l'élément non modifiable
                   item->setEditable(false);
                   item->setSelectable(false);
               }
           }
       }
       DatabaseConnection::closeDB();
       ui->view_3->setModel(model4);
       ui->view_3->horizontalHeader()->setVisible(false);
       ui->view_3->verticalHeader()->setVisible(false);
       ui->view_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       } else {
       qWarning() << "Impossible de se connecter à la base de données.";
       }

}
//load les salles
void WelcomeWindow::loadSalles1(){
    if(DatabaseConnection::DBconnect()){
        QSqlQuery query;
        query.exec("select *from salle");
        if(query.isActive()){
            int row = 0;
            while(query.next()){
                QString numbersalle = query.value("numbersalle").toString();
                QString affecta = query.value("affecta").toString();
                QString moduleen = query.value("moduleen").toString();
                QString heure = query.value("heure").toString();

                model3->setItem(row, 0, new QStandardItem(numbersalle));
                model3->setItem(row, 1, new QStandardItem(affecta));
                model3->setItem(row, 3, new QStandardItem(moduleen));
                model3->setItem(row, 2, new QStandardItem(heure));
                row++;
            }

        }
        for (int row = 0; row < model3->rowCount(); ++row) {
            for (int col = 0; col < model3->columnCount(); ++col) {
                QStandardItem *item = model3->item(row, col);
                if (item) {
                    // Rendre l'élément non modifiable
                   // item->setEditable(false);
                   // item->setSelectable(false);
                }
            }
        }
        //model->setTable("etudiant");
        //model->select();
        DatabaseConnection::closeDB();
        ui->salleview_3->setModel(model3);
        ui->salleview_3->horizontalHeader()->setVisible(false);
        ui->salleview_3->verticalHeader()->setVisible(false);
        ui->salleview_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
        qWarning() << "Impossible de se connecter à la base de données.";
    }

}
void WelcomeWindow::ajouterSouMaster(){
    QString entreprise = ui->entreprise_3->text();
    QString codeapo = ui->cne_3->text();
    QDateTime date_time = ui->date_3->dateTime();
    QString jury = ui->members_3->text();
    QString sujet = ui->sujet_3->text();

    QString pasval="A VENIR";

    if(DatabaseConnection::DBconnect()){
    QSqlQuery query;
    query.prepare("insert into soutenanceM(codeapo,entreprise,sujet,dateheure,statut,membreJury) VALUES ('"+codeapo+"','"+entreprise+"','"+sujet+"','"+date_time.toString("dd-MM-yyyy HH:mm")+"','"+pasval+"','"+jury+"')");
    //query.exec(insertQuery);
    if (query.exec()) {
        qDebug() << "Insertion réussie!";
    } else {
        qDebug() << "Erreur lors de l'insertion:" << query.lastError().text();
    }
    DatabaseConnection::closeDB();
    }else{
    qWarning() << "Impossible de se connecter à la base de données.";
    }
}
//une fonction pour filtrer selon la filiere
void WelcomeWindow::FiliereFiltre(){
    if(DatabaseConnection::DBconnect()){
        QString selectedF = ui->inputFilter->text();
        QSqlQuery query;
        query.exec("SELECT * FROM masterEtudiants where filiere='"+selectedF+"'");
        if(query.isActive()){
            int row = 0;
            while(query.next()){
                QString code_apogee = query.value("codeapo").toString();
                QString nom = query.value("nom").toString();
                QString prenom = query.value("prenom").toString();
                QString filiere = query.value("filiere").toString();

                model5->setItem(row, 0, new QStandardItem(code_apogee));
                model5->setItem(row, 1, new QStandardItem(nom));
                model5->setItem(row, 2, new QStandardItem(prenom));
                model5->setItem(row, 3, new QStandardItem(filiere));
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
        filtrerParFiliere();
        ui->masterView_2->setModel(model5);
        ui->masterView_2->horizontalHeader()->setVisible(false);
        ui->masterView_2->verticalHeader()->setVisible(false);
        ui->masterView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
       // qWarning() << "Impossible de se connecter à la base de données.";
    }


}
//charger les 10 etudiants inscrits
void WelcomeWindow::loadLastMasters()
{

    if(DatabaseConnection::DBconnect()){
           QSqlQuery query;
           query.exec("SELECT * FROM masterEtudiants ORDER BY date_ajout DESC LIMIT 10");
           if(query.isActive()){
               int row = 0;
               while(query.next()){
                   QString codeapo = query.value("codeapo").toString();
                   QString nom = query.value("nom").toString();
                   QString prenom = query.value("prenom").toString();
                   QString filiere = query.value("filiere").toString();

                   dashModelMaster->setItem(row, 0, new QStandardItem(codeapo));
                   dashModelMaster->setItem(row, 1, new QStandardItem(nom));
                   dashModelMaster->setItem(row, 2, new QStandardItem(prenom));
                   dashModelMaster->setItem(row, 3, new QStandardItem(filiere));
                   row++;
               }
           }
           for (int row = 0; row < dashModelMaster->rowCount(); ++row) {
               for (int col = 0; col < dashModel->columnCount(); ++col) {
                   QStandardItem *item = dashModel->item(row, col);
                   if (item) {
                       // Rendre l'élément non modifiable
                       item->setEditable(false);
                       item->setSelectable(false);
                   }
               }
           }
           DatabaseConnection::closeDB();
           ui->masterView->setModel(dashModelMaster);
           ui->masterView->horizontalHeader()->setVisible(false);
           ui->masterView->verticalHeader()->setVisible(false);
           ui->masterView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       } else {
           qWarning() << "Impossible de se connecter à la base de données.";
       }
}
//filtrer les etudaints du licence Techniques
void WelcomeWindow::FiliereLicence(){
    if(DatabaseConnection::DBconnect()){
        QString selectedF = ui->inputFilter_2->text();
        QSqlQuery query;
        query.exec("SELECT * FROM licenceEtude  where filiere='"+selectedF+"'");
        if(query.isActive()){
            int row = 0;
            while(query.next()){
                QString code_apogee = query.value("codeapo").toString();
                QString nom = query.value("nom").toString();
                QString prenom = query.value("prenom").toString();
                QString filiere = query.value("filiere").toString();

                model6->setItem(row, 0, new QStandardItem(code_apogee));
                model6->setItem(row, 1, new QStandardItem(nom));
                model6->setItem(row, 2, new QStandardItem(prenom));
                model6->setItem(row, 3, new QStandardItem(filiere));
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
        filtrerParFiliere();
        ui->tableView->setModel(model6);
        ui->tableView->horizontalHeader()->setVisible(false);
        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
       // qWarning() << "Impossible de se connecter à la base de données.";
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
}


void WelcomeWindow::on_cyclebtn_clicked()
{

}


void WelcomeWindow::on_addBtn_clicked()
{



}


void WelcomeWindow::on_sout_valid_btn_clicked()
{
   // savesoutenance();

}


void WelcomeWindow::on_pushButton_clicked()
{

}

