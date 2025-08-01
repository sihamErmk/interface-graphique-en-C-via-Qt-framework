#ifndef SUPPRIMERMASTERPROF_H
#define SUPPRIMERMASTERPROF_H
#include "suppression.h"

#include <QDialog>

namespace Ui {
class supprimerMasterProf;
}

class supprimerMasterProf : public QDialog
{
    Q_OBJECT
public :
    void supprimerMaster();

public:
    explicit supprimerMasterProf(QWidget *parent = nullptr);
    ~supprimerMasterProf();

private:
    Ui::supprimerMasterProf *ui;
    Suppression *sup3;
};

#endif // SUPPRIMERMASTERPROF_H
