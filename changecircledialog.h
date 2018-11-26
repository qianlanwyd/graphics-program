#ifndef CHANGECIRCLEDIALOG_H
#define CHANGECIRCLEDIALOG_H

#include <QDialog>

namespace Ui {
class changecircleDialog;
}

class changecircleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit changecircleDialog(QWidget *parent = 0);
    ~changecircleDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::changecircleDialog *ui;
};

#endif // CHANGECIRCLEDIALOG_H
