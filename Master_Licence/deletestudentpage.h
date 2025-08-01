#ifndef DELETESTUDENTPAGE_H
#define DELETESTUDENTPAGE_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class DeleteStudentPage;
}

class DeleteStudentPage : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteStudentPage(QWidget *parent = nullptr);
    ~DeleteStudentPage();
private:
    Ui::DeleteStudentPage *ui;
};


#endif // DELETESTUDENTPAGE_H
