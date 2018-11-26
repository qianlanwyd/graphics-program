#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

class Ellipse_
{
private:
    int x, y;
    int a, b;
    void Symmetry(int tx, int ty);


public:
    Ellipse_(int x, int y, int a, int b);
    int getx() { return x; }
    int gety() { return y; }
    int geta() { return a; }
    int getb() { return b; }

    void setx(int i) { x = i; }
    void sety(int i) { y = i; }
    void seta(int i) { a = i; }
    void setb(int i) { b = i; }

    void Midpoint();
};

#endif // ELLIPSE_H
