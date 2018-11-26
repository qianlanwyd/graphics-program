#ifndef SCALEELLIPSEDIALOG_H
#define SCALEELLIPSEDIALOG_H

#include <QDialog>

namespace Ui {
class scaleellipseDialog;
}

class scaleellipseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit scaleellipseDialog(QWidget *parent = 0);
    ~scaleellipseDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::scaleellipseDialog *ui;
};

#endif // SCALEELLIPSEDIALOG_H
