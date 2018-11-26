#ifndef CURVELIST_H
#define CURVELIST_H


#include"curve.h"
#include<list>

class CurveList
{
private:
    list<Curve*> curveList;

public:
    list<Curve*> getCurveList() { return this->curveList; }
    int addCurve(int *x, int *y, int num);
    void deleteCurve(int no);

    void clearAll()
    {
        curveList.clear();
    }
};

#endif // CURVELIST_H
