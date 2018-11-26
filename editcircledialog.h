#ifndef EDITCIRCLEDIALOG_H
#define EDITCIRCLEDIALOG_H

#include <QDialog>

namespace Ui {
class editcircleDialog;
}

class editcircleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editcircleDialog(QWidget *parent = 0);
    ~editcircleDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::editcircleDialog *ui;
    void display();
};

#endif // EDITCIRCLEDIALOG_H
