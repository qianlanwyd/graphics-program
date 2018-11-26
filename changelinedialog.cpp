#include "changelinedialog.h"
#include "ui_changelinedialog.h"
#include "myshape.h"
#include"QMessageBox"

changelineDialog::changelineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changelineDialog)
{
    ui->setupUi(this);
}

changelineDialog::~changelineDialog()
{
    delete ui;
}

void changelineDialog::on_pushButton_clicked()
{
      int no=ui->spinBox->value();
      if(no>my_line->getLineList().size()){
            QMessageBox::about(NULL, "Error", "   不合法输入！      ");
            rejected();
        }
       ui->spinBox->setRange(1,my_line->getLineList().size());
       int x1 = ui->spinBox_2->value();
       int y1 = ui->spinBox_3->value();
       int x2 = ui->spinBox_4->value();
       int y2 = ui->spinBox_5->value();
       my_line->editLine(no, x1, y1, x2, y2);
       accept();

}

void changelineDialog::on_changelineDialog_accepted()
{

}
