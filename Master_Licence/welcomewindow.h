#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QInputDialog>
#include <iostream>
#include "loginpage.h"
#include "addstudentpage.h"
#include "deletestudentpage.h"
#include "addlicencestudent.h"
#include "supprimerlicence.h"
#include "addprof.h"
#include "supprimerprof.h"
#include "ajoutermaster.h"
#include "supprimermasterprof.h"
#include "ajoutermasteretudaintes.h"
#include "supprimermastereude.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeWindow; }
QT_END_NAMESPACE

class WelcomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    WelcomeWindow(QWidget *parent = nullptr);

    void loadStudentData();
    void loadDataAndUpdateModel();
    //licence Part starts
    //Dash part
    void countingStudents(int number);
    void loadLatStudents();
    //1)part student
     void loadLicenceStudent();
    void addStudents();
    void filtrerParLicenceType();
    //2)part Prof
    void loadProfs();
    //modules part
    void loadModels();
    void loadApp();
    //PART OF SALLES
    void loadSalles();
    //SOUTENANCE PARTIE
    void loadsoutenance();
    void savesoutenance();
    void mettreAJourHeure();
    void filtrer();
    //licence Part ends
    //master fonctions
    void chargerMaster();
    void CountMaster(int number);
    void chargerProfs();
    void afficherProfs();
    void loadLastsMaster();
    void chargerSout();
    void loadSalles1();
    void ajouterSouMaster();
    void ModelsAI();
    void ModelsIT();
    void FiliereFiltre();
    void loadLastMasters();
    void FiliereLicence();
    ~WelcomeWindow();


public slots:
    void boutonClique();
    void filtrerParFiliere();
    //void addStudent();
    //licence PART
   // void filtrerParlicenceFil();

private slots:
    void on_cyclebtn_clicked();

    void on_addBtn_clicked();

    void on_sout_valid_btn_clicked();

    void on_pushButton_clicked();

private:
    Ui::WelcomeWindow *ui;
    LoginPage *login;
    addProf *addprofrs;
    AddStudentPage *addstudentpage;
    DeleteStudentPage *deletestudentpage;
    QMessageBox *msgbox;
    QStandardItemModel *model;
    //licence partie
    QStandardItemModel *soutenancemodel;
   QStandardItemModel *modelSalle;
    QStandardItemModel *dashModel;
    supprimerLicence *supprimerlicenceEtudiant;
    addLicenceStudent *addlicencestudent;
    QStandardItemModel   *modelLicence;
    QStandardItemModel   *modelProf;
    supprimerProf *supprimeProf;
    //master partie
    QStandardItemModel   *modelMaster;
    ajouterMaster *ajouter;
    supprimerMasterProf *supProfMaster;
    QStandardItemModel  *modelProfs;
    QStandardItemModel *model1;
    QStandardItemModel *model2;
    QStandardItemModel *model3;
    QStandardItemModel *model4;
    QStandardItemModel *model5;
    ajouterMasterEtudaintes *ajouterEtud;
    supprimerMasterEude *supprimerEtudiantes;
    QStandardItemModel *dashModelMaster;
    QStandardItemModel *model6;

};
#endif // WELCOMEWINDOW_H
