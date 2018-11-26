#ifndef CHANGELINEDIALOG_H
#define CHANGELINEDIALOG_H

#include <QDialog>

namespace Ui {
class changelineDialog;
}

class changelineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit changelineDialog(QWidget *parent = 0);
    ~changelineDialog();

private slots:
    void on_pushButton_clicked();

    void on_changelineDialog_accepted();

private:
    Ui::changelineDialog *ui;
};

#endif // CHANGELINEDIALOG_H
