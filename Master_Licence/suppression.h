#ifndef SUPPRESSION_H
#define SUPPRESSION_H

#include <QDialog>

namespace Ui {
class Suppression;
}

class Suppression : public QDialog
{
    Q_OBJECT

public:
    explicit Suppression(QWidget *parent = nullptr);
    ~Suppression();

private:
    Ui::Suppression *ui;
};

#endif // SUPPRESSION_H
