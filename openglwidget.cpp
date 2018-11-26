#include "openglwidget.h"
#include"type.h"
#include"linelist.h"
#include"myshape.h"
#include <cmath>

#include <QDebug>
#include <QMessageBox>

OpenglWidget::OpenglWidget(QWidget *parent) : QOpenGLWidget(parent)
{
    click=0;
}

void OpenglWidget::initializeGL()
{


    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glOrtho(0, 800, 0, 500, -250, 250);

    glColor3f(0.0, 0.0, 0.0);
}

void OpenglWidget::resizeGL(int w, int h)
{
}

void OpenglWidget::paintGL()
{

    glBegin(GL_POINTS);
    draw();
    //qDebug()<<ftype;
    glEnd();
    glFlush();

}

void OpenglWidget::draw(){
    list<Line*> ll = my_line->getLineList();
    list<Line*>::iterator it;
          for (it = ll.begin(); it != ll.end(); it++)
              (*it)->DDA();
    list<Circle*> ll2 = my_circle->getCircleList();
    list<Circle*>::iterator it2;
          for (it2 = ll2.begin(); it2 != ll2.end(); it2++)
              (*it2)->Midpoint();
    list<Ellipse_*> ll3 = my_ellipse->getEllipseList();
    list<Ellipse_*>::iterator it3;
          for (it3 = ll3.begin(); it3 != ll3.end(); it3++)
              (*it3)->Midpoint();
    list<Curve*> ll4 = my_curve->getCurveList();
    list<Curve*>::iterator it4;
          for (it4 = ll4.begin(); it4 != ll4.end(); it4++)
               (*it4)->drawBSpline();
}

void OpenglWidget::mouseMoveEvent(QMouseEvent *event)
{

}

void OpenglWidget::mousePressEvent(QMouseEvent *event){
    if(ftype==LINE||ftype==CIRCLE||ftype==ELLIPSE){
        x1=event->pos().x();
        y1=500-event->pos().y();
        // qDebug()<<"x1:"<<x1<<y1;
        //update();
    }
    if(ftype==CURVE){
        qDebug()<<curve_num;
        qDebug()<<click;
        qDebug()<<my_curve->getCurveList().size();
        if(click==0){
            curvex=new int[curve_num];
            curvey=new int[curve_num];
        }
        curvex[click] = event->pos().x();
        curvey[click] = 500 - event->pos().y();
        if (click == curve_num - 1)
        {
            click = 0;
            my_curve->addCurve(curvex,curvey,curve_num);
            update();
        }
        else
            click++;
    }
}

void OpenglWidget::mouseReleaseEvent(QMouseEvent *event){
    qDebug()<<"yes";
    if (event->button() == Qt::LeftButton){
        x2=event->pos().x();
        y2=500-event->pos().y();
        //qDebug()<<"x2:"<<x2<<y2;
        switch(ftype)
        {
            case LINE: my_line->addLineVertex(x1,y1,x2,y2);update(); break;
            case CIRCLE: {int x = (x1+x2)/2;
                         int y = (y1+y2)/2;
                         int dx = x - x2;
                         int dy = y - y2;
                         int r = (int)(sqrt(dx*dx + dy*dy));
                         my_circle->addCircle(x,y,r);update(); break;}
            case ELLIPSE:{
                        int x = (x1+x2)/2;
                        int y = (y1+y2)/2;
                        int a = fabs((x1-x2)/2);
                        int b = fabs((y1-y2)/2);
                        my_ellipse->addEllipse(x, y, a, b);update();break;}
            default: break;
        }
    }
}



