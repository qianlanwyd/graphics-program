#include "circle.h"

Circle::Circle(int x, int y, int r)
{
    this->x = x;
    this->y = y;
    this->r = r;
}

void Circle::Midpoint()
{
    int tx = 0, ty = r;
    int d = 1 - r;

    int deltax = 3;
    int deltay = 5 - r - r;


    while (tx <= ty)
    {
        Symmetry(tx, ty);
        if (d <= 0)
        {
            d += deltax;
            deltax += 2;
            deltay += 2;
        }
        else
        {
            d += deltay;
            deltax += 2;
            deltay += 4;
            ty--;
        }
        tx++;
    }
}

void Circle::Symmetry(int tx, int ty)
{
    glVertex2i(x + tx, y + ty);
    glVertex2i(x - tx, y + ty);
    glVertex2i(x + tx, y - ty);
    glVertex2i(x - tx, y - ty);
    glVertex2i(x + ty, y + tx);
    glVertex2i(x - ty, y + tx);
    glVertex2i(x + ty, y - tx);
    glVertex2i(x - ty, y - tx);
}
