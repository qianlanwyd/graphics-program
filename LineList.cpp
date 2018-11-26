#include "linelist.h"

#include <QFile>
#include <QTextStream>
#include <list>
#include <QDebug>
#include<cmath>

int LineList::addLineVertex(int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
        return -1;

    if (x1<0||x1>800||y1<0||y1>500||x2<0||x2>800||y2<0||y2>800)
        return -2;
    qDebug()<<lineList.size();
    Line *line = new Line(x1, y1, x2, y2);
    list<Line*>::iterator it;
    for (it = lineList.begin(); it != lineList.end(); it++)
        if ((*it)->getx1() == line->getx1() && (*it)->gety1() == line->gety1() && (*it)->getx2() == line->getx2() && (*it)->gety2() == line->gety2())
        {
            delete line;
            return 0;
        }
    lineList.push_back(line);
    //updateFile();
    return 1;
}

void LineList::deleteLine(int no)
{
    list<Line*>::iterator it;
    int cnt = 1;
    for (it = lineList.begin(); cnt != no; it++)
        cnt++;
    lineList.erase(it);
}

int LineList::editLine(int no, int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
        return -1;

    if (x1<0||x1>800||y1<0||y1>500||x2<0||x2>800||y2<0||y2>500)
        return -2;

    list<Line*>::iterator it;
    int cnt = 1;
    for (it = lineList.begin(); it != lineList.end(); it++)
    {
        if ((*it)->getx1() == x1 && (*it)->gety1() == y1 && (*it)->getx2() == x2 && (*it)->gety2() == y2)
            if (cnt == no)
                return 1;
            else
                return 0;
        cnt++;
    }

    cnt = 1;
    for (it = lineList.begin(); cnt != no; it++)
        cnt++;
    (*it)->setx1(x1);
    (*it)->sety1(y1);
    (*it)->setx2(x2);
    (*it)->sety2(y2);
    return 1;

}
int LineList::rotateLine(int no, int ang)
{
    list<Line*>::iterator it;
    int cnt = 1;
    double angle = (double(ang) / 360 * (2*M_PI));
    for (it = lineList.begin(); it != lineList.end(); it++)
    {
        if (cnt == no){
            int x1=(*it)->getx1();
            int y1=(*it)->gety1();
            int x2=(*it)->getx2();
            int y2=(*it)->gety2();
            int tx=x2;
            int ty=y2;
            x2 = int((double(tx-x1))*cos(angle)+(double(ty-y1))*sin(angle)+x1);
            y2 = int((double(ty-y1))*cos(angle)-(double(tx-x1))*sin(angle)+y1);
            (*it)->setx2(x2);
            (*it)->sety2(y2);
            return 1;
        }

        cnt++;
    }
    return 0;

}

int LineList::tranLine(int no, int x,int y)
{
    list<Line*>::iterator it;
    int cnt = 1;
    for (it = lineList.begin(); it != lineList.end(); it++)
    {
        if (cnt == no){
            int x1=(*it)->getx1();
            int y1=(*it)->gety1();
            int x2=(*it)->getx2();
            int y2=(*it)->gety2();
            x1=x1+x;
            x2=x2+x;
            y1=y1+y;
            y2=y2+y;
            (*it)->setx1(x1);
            (*it)->sety1(y1);
            (*it)->setx2(x2);
            (*it)->sety2(y2);
            return 1;
        }

        cnt++;
    }
    return 0;

}
int LineList::scaleLine(int no, double x,double y)
{
    list<Line*>::iterator it;
    int cnt = 1;
    for (it = lineList.begin(); it != lineList.end(); it++)
    {
        if (cnt == no){
            int x1=(*it)->getx1();
            int y1=(*it)->gety1();
            int x2=(*it)->getx2();
            int y2=(*it)->gety2();
            int dx = x2 - x1;
            int dy = y2 - y1;
            x2=x2+int(x*dx);
            y2=y2+int(y*dy);
            (*it)->setx2(x2);
            (*it)->sety2(y2);
            return 1;
        }

        cnt++;
    }
    return 0;

}


