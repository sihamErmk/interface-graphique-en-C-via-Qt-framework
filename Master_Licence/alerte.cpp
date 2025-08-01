#include "alerte.h"
#include "ui_alerte.h"

ALERTE::ALERTE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ALERTE)
{
    ui->setupUi(this);
}

ALERTE::~ALERTE()
{
    delete ui;
}
