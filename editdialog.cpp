#include "editdialog.h"
#include "ui_editdialog.h"
#include "editlinedialog.h"
#include"editcircledialog.h"
#include"editellipsedialog.h"
#include"editcurvedialog.h"

editDialog::editDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editDialog)
{
    ui->setupUi(this);
}

editDialog::~editDialog()
{
    delete ui;
}

void editDialog::on_pushButton_clicked()
{
    editlineDialog *dlg = new editlineDialog();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->exec();
}

void editDialog::on_pushButton_2_clicked()
{
    editcircleDialog *dlg = new editcircleDialog();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->exec();
}

void editDialog::on_pushButton_3_clicked()
{
    editellipseDialog *dlg = new editellipseDialog();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->exec();

}

void editDialog::on_pushButton_4_clicked()
{
    editcurveDialog *dlg = new editcurveDialog();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->exec();
}
