#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <QMessageBox>
#include "database.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private:
    Ui::LoginPage *ui;
    QMessageBox *msgbox;
};

extern bool isUserConnected;

#endif // LOGINPAGE_H
