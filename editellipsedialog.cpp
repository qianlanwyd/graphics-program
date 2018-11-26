#include "editellipsedialog.h"
#include "ui_editellipsedialog.h"
#include"myshape.h"
#include"changeellipsedialog.h"
#include"tranellipsedialog.h"
#include"scaleellipsedialog.h"
#include<QMessageBox>

editellipseDialog::editellipseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editellipseDialog)
{
    ui->setupUi(this);
    ui->textBrowser->clear();
    this->display();
}

editellipseDialog::~editellipseDialog()
{
    delete ui;
}
void editellipseDialog::display()
{
    int cnt = 1;
    list<Ellipse_*> ll = my_ellipse->getEllipseList();
    list<Ellipse_*>::iterator it;

    for (it = ll.begin(); it != ll.end(); it++){
        QString Str = "";
        Str.append(QString::number(cnt));
        Str.append(". 圆心: (");
        Str.append(QString::number((*it)->getx()));
        Str.append(", ");
        Str.append(QString::number((*it)->gety()));
        Str.append(") 长半轴: ");
        Str.append(QString::number((*it)->geta()));
        Str.append(" 短半轴: ");
        Str.append(QString::number((*it)->getb()));
        cnt++;
        ui->textBrowser->append(Str);
    }
}
void editellipseDialog::on_pushButton_clicked()
{
    changeellipseDialog *dlg = new changeellipseDialog();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->exec();
    ui->textBrowser->clear();
    this->display();

}

void editellipseDialog::on_pushButton_2_clicked()
{
    int num=ui->spinBox->value();
    if(num>my_ellipse->getEllipseList().size()){
          QMessageBox::about(NULL, "Error", "   不合法输入！      ");
           return;
      }
    my_ellipse->deleteEllipse(num);
    ui->textBrowser->clear();
    this->display();
}

void editellipseDialog::on_pushButton_3_clicked()
{
    my_ellipse->clearAll();
    ui->textBrowser->clear();
    this->display();
}

void editellipseDialog::on_pushButton_4_clicked()
{
    tranellipseDialog *dlg = new  tranellipseDialog();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->exec();
    ui->textBrowser->clear();
    this->display();
}

void editellipseDialog::on_pushButton_5_clicked()
{
    scaleellipseDialog *dlg = new  scaleellipseDialog();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->exec();
    ui->textBrowser->clear();
    this->display();
}
