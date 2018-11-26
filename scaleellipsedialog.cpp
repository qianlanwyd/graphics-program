#include "scaleellipsedialog.h"
#include "ui_scaleellipsedialog.h"
#include<QMessageBox>
#include"myshape.h"

scaleellipseDialog::scaleellipseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scaleellipseDialog)
{
    ui->setupUi(this);
}

scaleellipseDialog::~scaleellipseDialog()
{
    delete ui;
}

void scaleellipseDialog::on_pushButton_clicked()
{
    int no=ui->spinBox->value();
    if(no>my_ellipse->getEllipseList().size()||no==0){
        QMessageBox::about(NULL, "Error", "   不合法输入！      ");
        rejected();
    }
    ui->spinBox->setRange(1,my_ellipse->getEllipseList().size());
    double x=ui->doubleSpinBox->value();
    my_ellipse->scaleEllipse(no,x);
    accept();
}
