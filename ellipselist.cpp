#include "ellipselist.h"

#include <QFile>
#include <QTextStream>

#include <QDebug>

int EllipseList::addEllipse(int x, int y, int a, int b)
{
    if (a == 0 || b == 0)
        return -2;

    if (x-a < 0 || x+a > 800 || y-b < 0 || y+b > 500)
        return -1;

    Ellipse_ *ellipse = new Ellipse_(x, y, a, b);
    list<Ellipse_*>::iterator it;
    for (it = ellipseList.begin(); it != ellipseList.end(); it++)
        if ((*it)->getx() == x && (*it)->gety() == y && (*it)->geta() == a && (*it)->getb() == b)
        {
            delete ellipse;
            return 0;
        }

    ellipseList.push_back(ellipse);
    return 1;
}

void EllipseList::deleteEllipse(int no)
{
    list<Ellipse_*>::iterator it;
    int cnt = 1;
    for (it = ellipseList.begin(); cnt != no; it++)
        cnt++;
    ellipseList.erase(it);
}

int EllipseList::tranEllipse(int no, int x,int y)
{
    list<Ellipse_*>::iterator it;
    int cnt = 1;
    for (it = ellipseList.begin(); it != ellipseList.end(); it++)
    {
        if (cnt == no){
            int x1=(*it)->getx();
            int y1=(*it)->gety();
            x1=x1+x;
            y1=y1+y;
            (*it)->setx(x1);
            (*it)->sety(y1);
            return 1;
        }

        cnt++;
    }
    return 0;

}

int EllipseList::scaleEllipse(int no, double x)
{
    list<Ellipse_*>::iterator it;
    int cnt = 1;
    for (it = ellipseList.begin(); it != ellipseList.end(); it++)
    {
        if (cnt == no){
            int a1=(int)((*it)->geta()*x);
            int b1=(int)((*it)->getb()*x);
            (*it)->seta(a1);
            (*it)->setb(b1);
            return 1;
        }

        cnt++;
    }
    return 0;

}
int EllipseList::editEllipse(int no, int x, int y, int a, int b)
{
    if (a == 0 || b == 0)
        return -2;
    if (x-a < 0 || x+a > 800 || y-b < 0 || y+b > 500)
        return -1;

    QList<point>::iterator it;
    int cnt = 1;
    for (it = ellipseList.begin(); it != ellipseList.end(); it++)
    {
        if ((*it)->getx() == x && (*it)->gety() == y && (*it)->geta() == a && (*it)->getb() == b)
            if (cnt == no)
                return 1;
            else
                return 0;
        cnt++;
    }

    cnt = 1;
    for (it = ellipseList.begin(); cnt != no; it++)
        cnt++;
    (*it)->setx(x);
    (*it)->sety(y);
    (*it)->seta(a);
    (*it)->setb(b);
    return 1;
}
