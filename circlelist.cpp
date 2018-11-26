#include "circlelist.h"

#include <QFile>
#include <QTextStream>

#include <QDebug>

int CircleList::addCircle(int x, int y, int r)
{
    if (r == 0)
        return -2;

    if (x-r < 0 || x+r > 800 || y-r <0 || y+r > 500)
        return -1;

    Circle *circle = new Circle(x, y, r);
    list<Circle*>::iterator it;
    for (it = circleList.begin(); it != circleList.end(); it++)
        if ((*it)->getx() == x && (*it)->gety() == y && (*it)->getr() == r)
        {
            delete circle;
            return 0;
        }

     circleList.push_back(circle);
     return 1;

}
int CircleList::tranCircle(int no, int x,int y)
{
    list<Circle*>::iterator it;
    int cnt = 1;
    for (it = circleList.begin(); it != circleList.end(); it++)
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
void CircleList::deleteCircle(int no)
{
    list<Circle*>::iterator it;
    int cnt = 1;
    for (it = circleList.begin(); cnt != no; it++)
        cnt++;
    circleList.erase(it);
}

int CircleList::editCircle(int no, int x, int y, int r)
{
    if (r == 0)
        return -2;
    if (x-r < 0 || x+r > 800 || y-r <0 || y+r > 500)
        return -1;
    list<Circle*>::iterator it;
    int cnt = 1;
    for (it = circleList.begin(); it != circleList.end(); it++)
    {
        if ((*it)->getx() == x && (*it)->gety() == y && (*it)->getr() == r)
            if (cnt == no)
                return 1;
            else
                return 0;
        cnt++;
    }

    cnt = 1;
    for (it = circleList.begin(); cnt != no; it++)
        cnt++;
    (*it)->setx(x);
    (*it)->sety(y);
    (*it)->setr(r);
    return 1;

}
int CircleList::scaleCircle(int no, double x)
{
    list<Circle*>::iterator it;
    int cnt = 1;
    for (it = circleList.begin(); it != circleList.end(); it++)
    {
        if (cnt == no){
            int x1=(int)(*it)->getr()*x;
            (*it)->setr(x1);
            return 1;
        }

        cnt++;
    }
    return 0;

}

