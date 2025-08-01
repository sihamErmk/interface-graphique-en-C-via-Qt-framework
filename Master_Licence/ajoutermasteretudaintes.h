#ifndef AJOUTERMASTERETUDAINTES_H
#define AJOUTERMASTERETUDAINTES_H
#include "alerte.h"
#include "echec.h"

#include <QDialog>

namespace Ui {
class ajouterMasterEtudaintes;
}

class ajouterMasterEtudaintes : public QDialog
{
    Q_OBJECT
public :
    void addStudentsMaster();

public:
    explicit ajouterMasterEtudaintes(QWidget *parent = nullptr);
    ~ajouterMasterEtudaintes();

private:
    Ui::ajouterMasterEtudaintes *ui;
    ALERTE *alerte2;
    Echec *echec2;
};

#endif // AJOUTERMASTERETUDAINTES_H
