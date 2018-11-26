#ifndef ELLIPSELIST_H
#define ELLIPSELIST_H


#include <list>

#include "ellipse.h"

class EllipseList
{
private:
    list<Ellipse_*> ellipseList;

public:
    list<Ellipse_*> getEllipseList() { return this->ellipseList; }
    int addEllipse(int x, int y, int a, int b);
    void deleteEllipse(int no);
    int editEllipse(int no, int x, int y, int a, int b);
    int tranEllipse(int no,int x,int y);
    int scaleEllipse(int no,double x);

    void clearAll()
    {
        ellipseList.clear();
    }

};

#endif // ELLIPSELIST_H
