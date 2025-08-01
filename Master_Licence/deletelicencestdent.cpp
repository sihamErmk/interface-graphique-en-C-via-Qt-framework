#include "deletelicencestdent.h"
#include "ui_deletelicencestdent.h"

deleteLicenceStdent::deleteLicenceStdent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteLicenceStdent)
{
    ui->setupUi(this);
}

deleteLicenceStdent::~deleteLicenceStdent()
{
    delete ui;
}
