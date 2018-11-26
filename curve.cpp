#include "curve.h"

Curve::Curve(int *x, int *y, int num)
{
    this->x = x;
    this->y = y;
    this->num = num;
}

void Curve::drawBSpline()
{
    int n = 100;
    float f1, f2, f3, f4;
    float deltaT = 1.0 / n;
    float T;
    int num_seg = num - 3;

    glBegin(GL_LINE_STRIP);
    for (int j = 0; j < num_seg; j++) {
        for (int i = 0; i <= n; i++) {

            T = i * deltaT;

            f1 = (-T*T*T + 3 * T*T - 3 * T + 1) / 6.0;
            f2 = (3 * T*T*T - 6 * T*T + 4) / 6.0;
            f3 = (-3 * T*T*T + 3 * T*T + 3 * T + 1) / 6.0;
            f4 = (T*T*T) / 6.0;

            glVertex2f(f1*x[j] + f2*x[j + 1] + f3*x[j + 2] + f4*x[j + 3],
                f1*y[j] + f2*y[j + 1] + f3*y[j + 2] + f4*y[j+3]);
        }
    }

    glEnd();
    glFlush();
}
