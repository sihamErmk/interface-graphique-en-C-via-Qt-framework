#ifndef ADDPROF_H
#define ADDPROF_H

#include <QWidget>

namespace Ui {
class AddProf;
}

class AddProf : public QWidget
{
    Q_OBJECT

public:
    explicit AddProf(QWidget *parent = nullptr);
    void add();
    void clearLineEditFields();
    ~AddProf();

signals:
    void boutonClicked();

private slots:
    void onBoutonClicked()
    {
        emit boutonClicked();
    }

private:
    Ui::AddProf *ui;
};

#endif // ADDPROF_H
