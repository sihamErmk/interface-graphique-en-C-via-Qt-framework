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
    void delete_stud();
    ~DeleteStudentPage();
private:
    Ui::DeleteStudentPage *ui;

signals:
    void boutonClicked();


private slots:
    void onBoutonClicked()
    {
        emit boutonClicked();
    }
};


#endif // DELETESTUDENTPAGE_H
