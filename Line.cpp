#include "line.h"
#include <cmath>

Line::Line(int x1, int y1, int x2, int y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

void Line::DDA()
{
    float x = 0.0;
    float y = 0.0;
    float m = 0.0;
    float dx = x2 - x1;
    float dy = y2 - y1;
    if (fabs(dx) > 1e-6)
    {
        m = dy / dx;
        if (m <= 1 && m >= -1)
        {
            if (x1 <= x2)
            {
                y = y1;
                for (x = x1; x <= x2; x++)
                {
                    glVertex2i(x, int(y + 0.5));
                    y += m;
                }
            }
            else
            {
                y = y2;
                for (x = x2; x <= x1; x++)
                {
                    glVertex2i(x, int(y + 0.5));
                    y += m;
                }
            }
        }
        if (m>1 || m<-1)
        {
            m = 1 / m;
            if (y1 <= y2)
            {
                x = x1;
                for (y = y1; y <= y2; y++)
                {
                    glVertex2i(int(x + 0.5), y);
                    x += m;
                }
            }
            else
            {
                x = x2;
                for (y = y2; y <= y1; y++)
                {
                    glVertex2i(int(x + 0.5), y);
                    x += m;
                }
            }
        }
    }
    else
    {
        int x = x1;
        int y = 0;
        y = (y1 <= y2) ? y1 : y2;
        int d = fabs((double)(y1 - y2));
        while (d >= 0)
        {
            glVertex2i(x, y);
            y++;
            d--;
        }
    }
}
