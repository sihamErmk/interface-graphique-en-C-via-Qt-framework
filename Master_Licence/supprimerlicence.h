#ifndef SUPPRIMERLICENCE_H
#define SUPPRIMERLICENCE_H
#include "suppression.h"
#include <QDialog>

namespace Ui {
class supprimerLicence;
}

class supprimerLicence : public QDialog
{
    Q_OBJECT
public:
    void supprimerlicence();
    void clearLineEditFields();


public:
    explicit supprimerLicence(QWidget *parent = nullptr);
    ~supprimerLicence();


private:
    Ui::supprimerLicence *ui;
    Suppression *sup;

};

#endif // SUPPRIMERLICENCE_H
