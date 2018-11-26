#ifndef TRANELLIPSEDIALOG_H
#define TRANELLIPSEDIALOG_H

#include <QDialog>

namespace Ui {
class tranellipseDialog;
}

class tranellipseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit tranellipseDialog(QWidget *parent = 0);
    ~tranellipseDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::tranellipseDialog *ui;
};

#endif // TRANELLIPSEDIALOG_H
