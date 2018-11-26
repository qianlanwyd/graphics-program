#include "changeellipsedialog.h"
#include "ui_changeellipsedialog.h"
#include<QMessageBox>
#include"myshape.h"

changeellipseDialog::changeellipseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeellipseDialog)
{
    ui->setupUi(this);
}

changeellipseDialog::~changeellipseDialog()
{
    delete ui;
}

void changeellipseDialog::on_pushButton_clicked()
{
    int no=ui->spinBox->value();
    if(no>my_ellipse->getEllipseList().size()){
          QMessageBox::about(NULL, "Error", "   不合法输入！      ");
          rejected();
      }
     ui->spinBox->setRange(1,my_ellipse->getEllipseList().size());
     int x = ui->spinBox_2->value();
     int y = ui->spinBox_3->value();
     int a = ui->spinBox_4->value();
     int b = ui->spinBox_5->value();
     my_ellipse->editEllipse(no,x,y,a,b);
     accept();
}
