#ifndef CIRCLE_H
#define CIRCLE_H

#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

class Circle
{
private:
    int x, y;
    int r;
    void Symmetry(int tx, int ty);

public:
    Circle(int x, int y, int r);
    int getx() { return x; }
    int gety() { return y; }
    int getr() { return r; }

    void setx(int i) { x = i; }
    void sety(int i) { y = i; }
    void setr(int i) { r = i; }

    void Midpoint();
};

#endif // CIRCLE_H
