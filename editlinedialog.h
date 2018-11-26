#ifndef EDITLINEDIALOG_H
#define EDITLINEDIALOG_H

#include <QDialog>

namespace Ui {
class editlineDialog;
}

class editlineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editlineDialog(QWidget *parent = 0);
    ~editlineDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::editlineDialog *ui;
    void display();
};

#endif // EDITLINEDIALOG_H
