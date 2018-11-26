#ifndef SCALELINEDIALOG_H
#define SCALELINEDIALOG_H

#include <QDialog>

namespace Ui {
class scalelineDialog;
}

class scalelineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit scalelineDialog(QWidget *parent = 0);
    ~scalelineDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::scalelineDialog *ui;
};

#endif // SCALELINEDIALOG_H
