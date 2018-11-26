#ifndef EDITELLIPSEDIALOG_H
#define EDITELLIPSEDIALOG_H

#include <QDialog>

namespace Ui {
class editellipseDialog;
}

class editellipseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editellipseDialog(QWidget *parent = 0);
    ~editellipseDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::editellipseDialog *ui;
    void display();
};

#endif // EDITELLIPSEDIALOG_H
