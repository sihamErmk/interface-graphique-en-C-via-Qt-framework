#ifndef ADDPROF_H
#define ADDPROF_H

#include <QDialog>
#include "alerte.h"

namespace Ui {
class addProf;
}

class addProf : public QDialog
{
    Q_OBJECT
public :
    void addProfs();

public:
    explicit addProf(QWidget *parent = nullptr);
    ~addProf();

private:
    Ui::addProf *ui;
    ALERTE *alerte4;
};

#endif // ADDPROF_H
