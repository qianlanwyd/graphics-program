#include "tranellipsedialog.h"
#include "ui_tranellipsedialog.h"
#include"myshape.h"
#include<QMessageBox>

tranellipseDialog::tranellipseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tranellipseDialog)
{
    ui->setupUi(this);
}

tranellipseDialog::~tranellipseDialog()
{
    delete ui;
}

void tranellipseDialog::on_pushButton_clicked()
{
    int no=ui->spinBox->value();
    if(no>my_ellipse->getEllipseList().size()){
        QMessageBox::about(NULL, "Error", "   不合法输入！      ");
        rejected();
    }
    ui->spinBox->setRange(1,my_ellipse->getEllipseList().size());
    int x=ui->spinBox_2->value();
    int y=ui->spinBox_3->value();
    my_ellipse->tranEllipse(no,x,y);
    accept();
}
