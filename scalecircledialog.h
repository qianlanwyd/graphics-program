#ifndef SCALECIRCLEDIALOG_H
#define SCALECIRCLEDIALOG_H

#include <QDialog>

namespace Ui {
class scalecircleDialog;
}

class scalecircleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit scalecircleDialog(QWidget *parent = 0);
    ~scalecircleDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::scalecircleDialog *ui;
};

#endif // SCALECIRCLEDIALOG_H
