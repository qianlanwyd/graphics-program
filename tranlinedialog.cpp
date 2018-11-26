#include "tranlinedialog.h"
#include "ui_tranlinedialog.h"
#include"myshape.h"
#include"QDebug"
#include"QMessageBox"

tranlineDialog::tranlineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tranlineDialog)
{
    ui->setupUi(this);
}

tranlineDialog::~tranlineDialog()
{
    delete ui;
}

void tranlineDialog::on_pushButton_clicked()
{
    //qDebug()<<"max"<<ui->spinBox->maximum();
    int no=ui->spinBox->value();
    if(no>my_line->getLineList().size()){
        QMessageBox::about(NULL, "Error", "   不合法输入！      ");
        rejected();
    }
    ui->spinBox->setRange(1,my_line->getLineList().size());
    int x=ui->spinBox_2->value();
    int y=ui->spinBox_3->value();
    my_line->tranLine(no,x,y);
    accept();
}
