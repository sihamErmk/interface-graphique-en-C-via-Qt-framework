#ifndef ADDSOUTENANCE_H
#define ADDSOUTENANCE_H

#include <QDialog>

namespace Ui {
class addSoutenance;
}

class addSoutenance : public QDialog
{
    Q_OBJECT

public:
    explicit addSoutenance(QWidget *parent = nullptr);
    ~addSoutenance();

private:
    Ui::addSoutenance *ui;
};

#endif // ADDSOUTENANCE_H
