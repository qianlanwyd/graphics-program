#ifndef CURVE_H
#define CURVE_H

#include <GL/gl.h>
#include <GL/glu.h>
using namespace std;

class Curve
{
private:
    int num;
    int *x;
    int *y;

public:
    Curve(int *x, int *y, int num);

    int* getx() { return x; }
    int* gety() { return y; }
    int getnum() { return num; }

    void drawBSpline();
};

#endif // CURVE_H
