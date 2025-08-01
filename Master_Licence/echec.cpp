#include "echec.h"
#include "ui_echec.h"

Echec::Echec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Echec)
{
    ui->setupUi(this);
}

Echec::~Echec()
{
    delete ui;
}
