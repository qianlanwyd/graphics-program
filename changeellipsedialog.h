#ifndef CHANGEELLIPSEDIALOG_H
#define CHANGEELLIPSEDIALOG_H

#include <QDialog>

namespace Ui {
class changeellipseDialog;
}

class changeellipseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit changeellipseDialog(QWidget *parent = 0);
    ~changeellipseDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::changeellipseDialog *ui;
};

#endif // CHANGEELLIPSEDIALOG_H
