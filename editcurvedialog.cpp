#include "editcurvedialog.h"
#include "ui_editcurvedialog.h"
#include"myshape.h"
#include<QMessageBox>


editcurveDialog::editcurveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcurveDialog)
{
    ui->setupUi(this);
    ui->textBrowser->clear();
    this->display();
}

void editcurveDialog::display()
{
    int cnt = 1;
    list<Curve*> ll = my_curve->getCurveList();
    list<Curve*>::iterator it;

    for (it = ll.begin(); it != ll.end(); it++){
        QString Str = "";
        Str.append(QString::number(cnt));
        Str.append(". 控制点数: ");
        Str.append(QString::number((*it)->getnum()));
        Str.append(", ");
        Str.append(" 各点坐标: ");
        for(int i=0;i<(*it)->getnum();i++){
            Str.append("(");
            Str.append(QString::number(((*it)->getx())[i]));
            Str.append(",");
            Str.append(QString::number(((*it)->gety())[i]));
            Str.append(") ");
        }
        cnt++;
        ui->textBrowser->append(Str);
    }
}

editcurveDialog::~editcurveDialog()
{
    delete ui;
}

void editcurveDialog::on_pushButton_clicked()
{
    int num=ui->spinBox->value();
    if(num>my_curve->getCurveList().size()){
          QMessageBox::about(NULL, "Error", "   不合法输入！      ");
           return;
      }
    my_curve->deleteCurve(num);
    ui->textBrowser->clear();
    this->display();
}
