#ifndef AJOUTERMASTER_H
#define AJOUTERMASTER_H
#include "alerte.h"
#include "echec.h"

#include <QDialog>

namespace Ui {
class ajouterMaster;
}

class ajouterMaster : public QDialog
{
    Q_OBJECT
public:
    void ajouterMasterR();

public:
    explicit ajouterMaster(QWidget *parent = nullptr);
    ~ajouterMaster();

private:
    Ui::ajouterMaster *ui;
    ALERTE *alerte3;
    Echec *echec3;
};

#endif // AJOUTERMASTER_H
