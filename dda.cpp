#include <stdio.h>
#include <iostream>
#include <math.h>
#include <dos.h>
#include <graphics.h>
using namespace std;
class assign
{
private:
    int x, y;

public:
    void circleBres(int xc, int yc, int r)
    {
        int x = 0, y = r; // initial conditionx

        int d = 3 - 2 * r; // initial decision parameter
        while (y >= x)

        {
            if (d > 0)

            {

                y--;
                x++;

                d = d + 4 * x - 4 * y + 10;
            }

            else
            {

                d = d + 4 * x + 6;
                x++;
            }

            putpixel(xc + x, yc + y, WHITE); // apply symmetry to all octates

            putpixel(xc - x, yc + y, WHITE);

            putpixel(xc + x, yc - y, WHITE);

            putpixel(xc - x, yc - y, WHITE);

            putpixel(xc + y, yc + x, WHITE);

            putpixel(xc - y, yc + x, WHITE);

            putpixel(xc + y, yc - x, WHITE);

            putpixel(xc - y, yc - x, WHITE);
        }
    }
};
// dda algorithm
void drawlines(int x1, int y1, int x2, int y2)
{
    float x, y, dx, dy, len, xi, yi;
    int i;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
    {
        len = abs(dx);
    }
    else
    {
        len = abs(dy);
    }
    xi = dx / len;
    yi = dy / len;
    putpixel(x1, y1, 15);
    x = x1;
    y = y1;
    for (i = 0; i < len; i++)
    {
        x = x + xi;
        y = y + yi;
        putpixel(x, y, 15);
    }
}

int main()
{
    int xc, yc, r, r1;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    cout << "enter coord";
    cin >> xc >> yc;
    cout << "enter r";
    cin >> r;
    cout << "enter r1";
    cin >> r1;
    assign a, b; // class objects
    a.circleBres(xc, yc, r);
    b.circleBres(xc, yc, r1);
    int x1, x2, y1, y2, x3, y3;
    cout << "enter first co-ordinate";
    cin >> x1 >> y1;
    cout << "enter second co-ordinate";
    cin >> x2 >> y2;
    cout << "enter third co-ordinate";
    cin >> x3 >> y3;
    drawlines(x1, y1, x2, y2);
    drawlines(x2, y2, x3, y3);
    drawlines(x1, y1, x3, y3);
    getch();
}
