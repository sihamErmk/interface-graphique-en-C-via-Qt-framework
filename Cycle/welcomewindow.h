#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QInputDialog>
#include <QGraphicsDropShadowEffect>
#include <QDateTime>
#include <QTimer>
#include <QFileDialog>
#include <iostream>
#include "loginpage.h"
#include "addstudentpage.h"
#include "deletestudentpage.h"
#include "addprof.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeWindow; }
QT_END_NAMESPACE

class WelcomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    WelcomeWindow(QWidget *parent = nullptr);
    void loadStudentData();
    void studentCount(int type);
    void loadProfData();
    void loadLastStudentRecord();
    void loadSoutData();
    void saveSoutDetail();
    void loadModS1Data();
    void loadModS3Data();
    void loadSalleData();
    ~WelcomeWindow();


public slots:
    void boutonClique();
    void filtrer();
    void mettreAJourHeure();

private:
    Ui::WelcomeWindow *ui;
    LoginPage *login;
    AddStudentPage *addstudentpage;
    AddProf *addprofpage;
    DeleteStudentPage *deletestudentpage;
    QMessageBox *msgbox;
    QStandardItemModel *model;
    QStandardItemModel *model_1;
    QStandardItemModel *model_2;
    QStandardItemModel *model_3;
    QStandardItemModel *model_4;
    QStandardItemModel *model_5;
    QStandardItemModel *model_6;
    QTimer *timer;
};
#endif // WELCOMEWINDOW_H
