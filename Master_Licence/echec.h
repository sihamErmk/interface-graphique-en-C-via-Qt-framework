#ifndef ECHEC_H
#define ECHEC_H

#include <QDialog>

namespace Ui {
class Echec;
}

class Echec : public QDialog
{
    Q_OBJECT

public:
    explicit Echec(QWidget *parent = nullptr);
    ~Echec();

private:
    Ui::Echec *ui;
};

#endif // ECHEC_H
