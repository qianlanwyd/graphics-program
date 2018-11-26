#ifndef TRANCIRCLEDIALOG_H
#define TRANCIRCLEDIALOG_H

#include <QDialog>

namespace Ui {
class trancircleDialog;
}

class trancircleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit trancircleDialog(QWidget *parent = 0);
    ~trancircleDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::trancircleDialog *ui;
};

#endif // TRANCIRCLEDIALOG_H
