#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "type.h"
#include "editdialog.h"
#include "myshape.h"
#include"openglwidget.h"
#include <QDebug>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ftype=LINE;
    //qDebug()<<ftype;
}

void MainWindow::on_pushButton_2_clicked()
{
    editDialog *dlg = new editDialog();
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    dlg->exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    ftype=CIRCLE;

}

void MainWindow::on_pushButton_4_clicked()
{
    my_line->clearAll();
    my_circle->clearAll();
    my_ellipse->clearAll();
    my_curve->clearAll();
    update();
    QMessageBox::about(NULL,"OK", "重置成功");
}

void MainWindow::on_pushButton_5_clicked()
{
    ftype=ELLIPSE;
}

void MainWindow::on_pushButton_6_clicked()
{
    ftype=CURVE;
    curve_num=ui->spinBox->value();

}
