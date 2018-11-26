#include "curvelist.h"

#include <QFile>
#include <QTextStream>

#include <QDebug>

int CurveList::addCurve(int *x, int *y, int num)
{
    if (num < 4)
        return -2;
    for (int i = 0; i < num - 1; i++)
        for (int j = i + 1; j < num; j++)
            if (x[i] == x[j] && y[i] == y[j])
                return -1;

    list<Curve*>::iterator it;
    for (it = curveList.begin(); it != curveList.end(); it++)
    {
        if (num == (*it)->getnum())
        {
            bool flag = true;
            for (int i = 0; i < num; i++)
                if (x[i] != (*it)->getx()[i] || y[i] != (*it)->gety()[i])
                {
                    flag = false;
                    break;
                }
            if (flag == true)
                return 0;
        }
    }

    Curve *curve = new Curve(x, y, num);
    curveList.push_back(curve);
    return 1;
}

void CurveList::deleteCurve(int no)
{
    list<Curve*>::iterator it;
    int cnt = 1;
    for (it = curveList.begin(); cnt != no; it++)
        cnt++;
    curveList.erase(it);
}

