#include "rotatelinedialog.h"
#include "ui_rotatelinedialog.h"
#include"myshape.h"
#include"QMessageBox"

rotatelineDialog::rotatelineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rotatelineDialog)
{
    ui->setupUi(this);
}

rotatelineDialog::~rotatelineDialog()
{
    delete ui;
}

void rotatelineDialog::on_pushButton_clicked()
{
    int no=ui->spinBox->value();
    if(no>my_line->getLineList().size()){
        QMessageBox::about(NULL, "Error", "   不合法输入！      ");
        rejected();
    }
    ui->spinBox->setRange(1,my_line->getLineList().size());
    int ang=ui->spinBox_2->value();
    my_line->rotateLine(no,ang);
    accept();

}
