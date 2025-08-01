#ifndef ADDSTUDENTPAGE_H
#define ADDSTUDENTPAGE_H

#include <QWidget>
#include <QStandardItemModel>


namespace Ui {
class AddStudentPage;
}

class AddStudentPage : public QWidget
{
    Q_OBJECT

public:
    explicit AddStudentPage(QWidget *parent = nullptr);
    ~AddStudentPage();
    void add();

signals:
    void boutonClicked();

private slots:
    void onBoutonClicked()
    {
        emit boutonClicked();
    }
    void clearLineEditFields();

private:
    Ui::AddStudentPage *ui;
};

#endif // ADDSTUDENTPAGE_H
