#ifndef SUPPRIMERMASTEREUDE_H
#define SUPPRIMERMASTEREUDE_H
#include "suppression.h"

#include <QDialog>

namespace Ui {
class supprimerMasterEude;
}

class supprimerMasterEude : public QDialog
{
    Q_OBJECT
public:
    void supp();
    void  afficher();

public:
    explicit supprimerMasterEude(QWidget *parent = nullptr);
    ~supprimerMasterEude();

private:
    Ui::supprimerMasterEude *ui;
    Suppression *sup2;
};

#endif // SUPPRIMERMASTEREUDE_H
