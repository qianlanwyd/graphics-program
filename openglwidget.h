#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QVector>
#include <GL/gl.h>
#include <GL/glu.h>
#include"linelist.h"

class OpenglWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit OpenglWidget(QWidget *parent = nullptr);
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
signals:

public slots:

protected:
     void mousePressEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     void draw();
     int x1;
     int y1;
     int x2;
     int y2;
     int click;
     int *curvex;
     int *curvey;
};

#endif // OPENGLWIDGET_H
