#include "suppression.h"
#include "ui_suppression.h"

Suppression::Suppression(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Suppression)
{
    ui->setupUi(this);
}

Suppression::~Suppression()
{
    delete ui;
}
