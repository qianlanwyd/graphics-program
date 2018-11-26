#ifndef LINE_H
#define LINE_H
#include <GL/gl.h>
#include <GL/glu.h>

using namespace  std;

class Line
{
private:
    int x1, y1;
    int x2, y2;

public:
    Line(int x1, int y1, int x2, int y2);

    int getx1() { return x1; }
    int gety1() { return y1; }
    int getx2() { return x2; }
    int gety2() { return y2; }

    void setx1(int i) { x1 = i; }
    void sety1(int i) { y1 = i; }
    void setx2(int i) { x2 = i; }
    void sety2(int i) { y2 = i; }

    void DDA();
};

#endif // LINE_H
