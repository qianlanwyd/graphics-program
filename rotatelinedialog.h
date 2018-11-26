#ifndef ROTATELINEDIALOG_H
#define ROTATELINEDIALOG_H

#include <QDialog>

namespace Ui {
class rotatelineDialog;
}

class rotatelineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit rotatelineDialog(QWidget *parent = 0);
    ~rotatelineDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::rotatelineDialog *ui;
};

#endif // ROTATELINEDIALOG_H
