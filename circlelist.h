#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include <list>

#include "circle.h"

class CircleList
{
private:
    list<Circle*> circleList;

public:
    list<Circle*> getCircleList() { return this->circleList; }
    int addCircle(int x, int y, int r);
    void deleteCircle(int no);
    int editCircle(int no, int x, int y, int r);
    int tranCircle(int no,int x,int y);
    int scaleCircle(int no,double x);

    void clearAll()
    {
        circleList.clear();
    }

};

#endif // CIRCLELIST_H
