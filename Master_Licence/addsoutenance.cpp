#include "addsoutenance.h"
#include "ui_addsoutenance.h"

addSoutenance::addSoutenance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addSoutenance)
{
    ui->setupUi(this);
}

addSoutenance::~addSoutenance()
{
    delete ui;
}
