#ifndef ALERTE_H
#define ALERTE_H

#include <QDialog>

namespace Ui {
class ALERTE;
}

class ALERTE : public QDialog
{
    Q_OBJECT

public:
    explicit ALERTE(QWidget *parent = nullptr);
    ~ALERTE();

private:
    Ui::ALERTE *ui;
};

#endif // ALERTE_H
