#ifndef ADDLICENCESTUDENT_H
#define ADDLICENCESTUDENT_H
#include "alerte.h"
#include "echec.h"

#include <QDialog>

namespace Ui {
class addLicenceStudent;
}

class addLicenceStudent : public QDialog
{
    Q_OBJECT

public:
    explicit addLicenceStudent(QWidget *parent = nullptr);
    ~addLicenceStudent();
    void AddLicenceStudent();
    void clearLineEditFields();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addLicenceStudent *ui;
    ALERTE  *alerte1;
    Echec *echec1;

};

#endif // ADDLICENCESTUDENT_H
