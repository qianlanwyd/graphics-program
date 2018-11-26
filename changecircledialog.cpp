#include "changecircledialog.h"
#include "ui_changecircledialog.h"
#include "myshape.h"
#include<QMessageBox>

changecircleDialog::changecircleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changecircleDialog)
{
    ui->setupUi(this);
}

changecircleDialog::~changecircleDialog()
{
    delete ui;
}

void changecircleDialog::on_pushButton_clicked()
{
    int no=ui->spinBox->value();
    if(no>my_circle->getCircleList().size()){
          QMessageBox::about(NULL, "Error", "   不合法输入！      ");
          rejected();
      }
     ui->spinBox->setRange(1,my_circle->getCircleList().size());
     int x = ui->spinBox_2->value();
     int y = ui->spinBox_3->value();
     int r = ui->spinBox_4->value();
     my_circle->editCircle(no,x,y,r);
     accept();

}
