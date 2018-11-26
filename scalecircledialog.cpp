#include "scalecircledialog.h"
#include "ui_scalecircledialog.h"
#include"myshape.h"
#include<QMessageBox>

scalecircleDialog::scalecircleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scalecircleDialog)
{
    ui->setupUi(this);
}

scalecircleDialog::~scalecircleDialog()
{
    delete ui;
}

void scalecircleDialog::on_pushButton_clicked()
{
    int no=ui->spinBox->value();
    if(no>my_circle->getCircleList().size()||no==0){
        QMessageBox::about(NULL, "Error", "   不合法输入！      ");
        rejected();
    }
    ui->spinBox->setRange(1,my_circle->getCircleList().size());
    double x=ui->doubleSpinBox->value();
    my_circle->scaleCircle(no,x);
    accept();

}
