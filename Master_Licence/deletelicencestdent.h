#ifndef DELETELICENCESTDENT_H
#define DELETELICENCESTDENT_H

#include <QDialog>

namespace Ui {
class deleteLicenceStdent;
}

class deleteLicenceStdent : public QDialog
{
    Q_OBJECT

public:
    explicit deleteLicenceStdent(QWidget *parent = nullptr);
    ~deleteLicenceStdent();

private:
    Ui::deleteLicenceStdent *ui;
};

#endif // DELETELICENCESTDENT_H
