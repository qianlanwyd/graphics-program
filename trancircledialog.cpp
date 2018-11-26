#include "trancircledialog.h"
#include "ui_trancircledialog.h"
#include<QMessageBox>
#include"myshape.h"

trancircleDialog::trancircleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trancircleDialog)
{
    ui->setupUi(this);
}

trancircleDialog::~trancircleDialog()
{
    delete ui;
}

void trancircleDialog::on_pushButton_clicked()
{
    int no=ui->spinBox->value();
    if(no>my_circle->getCircleList().size()){
        QMessageBox::about(NULL, "Error", "   不合法输入！      ");
        rejected();
    }
    ui->spinBox->setRange(1,my_circle->getCircleList().size());
    int x=ui->spinBox_2->value();
    int y=ui->spinBox_3->value();
    my_circle->tranCircle(no,x,y);
    accept();
}
