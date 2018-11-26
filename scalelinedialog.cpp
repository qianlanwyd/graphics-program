#include "scalelinedialog.h"
#include "ui_scalelinedialog.h"
#include"myshape.h"
#include"QMessageBox"

scalelineDialog::scalelineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scalelineDialog)
{
    ui->setupUi(this);
}

scalelineDialog::~scalelineDialog()
{
    delete ui;
}

void scalelineDialog::on_pushButton_clicked()
{
    int no=ui->spinBox->value();
    if(no>my_line->getLineList().size()){
        QMessageBox::about(NULL, "Error", "   不合法输入！      ");
        rejected();
    }
    ui->spinBox->setRange(1,my_line->getLineList().size());
    double x=ui->doubleSpinBox->value();
    double y=ui->doubleSpinBox_2->value();
    my_line->scaleLine(no,x,y);
    accept();
}
