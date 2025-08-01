#ifndef SUPPRIMERPROF_H
#define SUPPRIMERPROF_H

#include <QDialog>
#include "suppression.h"

namespace Ui {
class supprimerProf;
}

class supprimerProf : public QDialog
{
    Q_OBJECT

public :
    void deleteProf();
public:
    explicit supprimerProf(QWidget *parent = nullptr);
    ~supprimerProf();

private:
    Ui::supprimerProf *ui;
    Suppression *sup5;
};

#endif // SUPPRIMERPROF_H
