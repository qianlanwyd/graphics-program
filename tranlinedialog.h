#ifndef TRANLINEDIALOG_H
#define TRANLINEDIALOG_H

#include <QDialog>

namespace Ui {
class tranlineDialog;
}

class tranlineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit tranlineDialog(QWidget *parent = 0);
    ~tranlineDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::tranlineDialog *ui;
};

#endif // TRANLINEDIALOG_H
