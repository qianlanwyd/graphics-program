#include "ellipse.h"

Ellipse_::Ellipse_(int x, int y, int a, int b)
{
    this->x = x;
    this->y = y;
    this->a = a;
    this->b = b;
}

void Ellipse_::Midpoint()
{
    double sqa = a*a;
    double sqb = b*b;

    int dx = 0;
    int dy = b;
    Symmetry(dx, dy);

    double d = sqb + sqa*(0.25 - b);

    while (sqb*(dx + 1) < sqa*(dy - 0.5))
    {
        if (d < 0)
        {
            d += sqb*(2 * dx + 3);
        }
        else
        {
            d += (sqb*(2 * dx + 3) + sqa*((-2)*dy + 2));
            --dy;
        }
        ++dx;
        Symmetry(dx, dy);
    }
    d = (b * (dx + 0.5)) * 2 + (a * (dy - 1)) * 2 - (a * b) * 2;
    while (dy > 0)
    {
        if (d < 0)
        {
            d += sqb * (2 * dx + 2) + sqa * ((-2) * dy + 3);
            ++dx;
        }
        else
        {
            d += sqa * ((-2) * dy + 3);
        }
        --dy;
        Symmetry(dx, dy);
    }
}

void Ellipse_::Symmetry(int tx, int ty)
{
    glVertex2i(x + tx, y + ty);
    glVertex2i(x + tx, y - ty);
    glVertex2i(x - tx, y + ty);
    glVertex2i(x - tx, y - ty);
}
