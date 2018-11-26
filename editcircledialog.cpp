#include "editcircledialog.h"
#include "ui_editcircledialog.h"
#include "openglwidget.h"
#include "myshape.h"
#include"changecircledialog.h"
#include"trancircledialog.h"
#include"scalecircledialog.h"
#include<QDebug>
#include<QMessageBox>

editcircleDialog::editcircleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcircleDialog)
{
    ui->setupUi(this);
    ui->textBrowser->clear();
    this->display();
}



editcircleDialog::~editcircleDialog()
{
    delete ui;
}

void editcircleDialog::display()
{
    int cnt = 1;
    list<Circle*> ll = my_circle->getCircleList();
    list<Circle*>::iterator it;

    for (it = ll.begin(); it != ll.end(); it++){
        QString Str = "";
        Str.append(QString::number(cnt));
        Str.append(". 圆心: (");
        Str.append(QString::number((*it)->getx()));
        Str.append(", ");
        Str.append(QString::number((*it)->gety()));
        Str.append(") 半径: ");
        Str.append(QString::number((*it)->getr()));
        cnt++;
        ui->textBrowser->append(Str);
    }
}

void editcircleDialog::on_pushButton_clicked()
{
    my_circle->clearAll();
    ui->textBrowser->clear();
    this->display();
}

void editcircleDialog::on_pushButton_2_clicked()
{
    int num=ui->spinBox->value();
    if(num>my_circle->getCircleList().size()){
          QMessageBox::about(NULL, "Error", "   不合法输入！      ");
           return;
      }
    my_circle->deleteCircle(num);
    ui->textBrowser->clear();
    this->display();
}

void editcircleDialog::on_pushButton_3_clicked()
{
    changecircleDialog *dlg = new changecircleDialog();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->exec();
    ui->textBrowser->clear();
    this->display();

}

void editcircleDialog::on_pushButton_4_clicked()
{
    trancircleDialog *dlg = new  trancircleDialog();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->exec();
    ui->textBrowser->clear();
    this->display();
}

void editcircleDialog::on_pushButton_5_clicked()
{
    scalecircleDialog *dlg = new  scalecircleDialog();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->exec();
    ui->textBrowser->clear();
    this->display();
}
