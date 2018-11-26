#ifndef LINELIST_H
#define LINELIST_H

#include <list>
#include "line.h"
class LineList
{
private:
    list<Line*> lineList;
public:
    list<Line*> getLineList() { return this->lineList; }
    int addLineVertex(int x1, int y1, int x2, int y2);
    void deleteLine(int no);
    int editLine(int no, int x1, int y1, int x2, int y2);
    int rotateLine(int no,int ang);
    int tranLine(int no,int x,int y);
    int scaleLine(int no,double x,double y);
    void clearAll()
    {
        lineList.clear();
    }

};

#endif // LINELIST_H
