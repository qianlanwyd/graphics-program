#ifndef EDITCURVEDIALOG_H
#define EDITCURVEDIALOG_H

#include <QDialog>

namespace Ui {
class editcurveDialog;
}

class editcurveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editcurveDialog(QWidget *parent = 0);
    ~editcurveDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::editcurveDialog *ui;
    void display();
};

#endif // EDITCURVEDIALOG_H
