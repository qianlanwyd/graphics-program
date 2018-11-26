#include "editlinedialog.h"
#include "ui_editlinedialog.h"
#include "openglwidget.h"
#include "myshape.h"
#include"changelinedialog.h"
#include"rotatelinedialog.h"
#include"tranlinedialog.h"
#include"scalelinedialog.h"
#include"QMessageBox"

editlineDialog::editlineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editlineDialog)
{
    ui->setupUi(this);
    ui->textBrowser->clear();
    this->display();
}

editlineDialog::~editlineDialog()
{
    delete ui;
}

void editlineDialog::display()
{
    int cnt = 1;
    list<Line*> ll = my_line->getLineList();
    list<Line*>::iterator it;

    for (it = ll.begin(); it != ll.end(); it++){
        QString lineStr = "";
        lineStr.append(QString::number(cnt));
        lineStr.append(". 起点坐标: (");
        lineStr.append(QString::number((*it)->getx1()));
        lineStr.append(", ");
        lineStr.append(QString::number((*it)->gety1()));
        lineStr.append(") 终点坐标: (");
        lineStr.append(QString::number((*it)->getx2()));
        lineStr.append(", ");
        lineStr.append(QString::number((*it)->gety2()));
        lineStr.append(")");
        cnt++;
        ui->textBrowser->append(lineStr);
    }
}

void editlineDialog::on_pushButton_clicked()
{
    changelineDialog *dlg = new changelineDialog();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->exec();
    ui->textBrowser->clear();
    this->display();
}

void editlineDialog::on_pushButton_2_clicked()
{
    my_line->clearAll();
    ui->textBrowser->clear();
    this->display();
}

void editlineDialog::on_pushButton_3_clicked()
{
    int num=ui->spinBox->value();
    if(num>my_line->getLineList().size()){
          QMessageBox::about(NULL, "Error", "   不合法输入！      ");
           return;
      }
    my_line->deleteLine(num);
    ui->textBrowser->clear();
    this->display();

}

void editlineDialog::on_pushButton_4_clicked()
{
    rotatelineDialog *dlg = new  rotatelineDialog();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->exec();
    ui->textBrowser->clear();
    this->display();
}

void editlineDialog::on_pushButton_5_clicked()
{
    tranlineDialog *dlg = new  tranlineDialog();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->exec();
    ui->textBrowser->clear();
    this->display();
}

void editlineDialog::on_pushButton_6_clicked()
{
    scalelineDialog *dlg = new  scalelineDialog();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->exec();
    ui->textBrowser->clear();
    this->display();
}
