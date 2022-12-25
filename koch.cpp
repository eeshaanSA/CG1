#include <iostream>
using namespace std;
#include <conio.h>
#include<graphics.h>
#include <dos.h>
#include <math.h>
void kcurve(int x1, int y1, int x2, int y2, int n)
{
    int x3, y3, x4, y4, x, y; // x3 y3 and x4 y4 are the points where we divide the line and x y are the tope pts of triangle
    float a = 60 * 3.14 / 180;
    x3 = (2 * x1 + x2) / 3;
    y3 = (2 * y1 + y2) / 3;
    x4 = (x1 + 2 * x2) / 3;
    y4 = (y1 + 2 * y2) / 3;
    x = x3 + (x4 - x3) * cos(a) + (y4 - y3) * sin(a); // x3+ since x is ahead of x3
    y = y3 - (x4 - x3) * sin(a) + (y4 - y3) * cos(a); // y3- since we go down as y3 > y
    if (n > 1)
    {
        kcurve(x1, y1, x3, y3, n - 1);
        kcurve(x3, y3, x, y, n - 1);
        kcurve(x, y, x4, y4, n - 1);
        kcurve(x4, y4, x2, y2, n - 1); // 4 times since the line seg is divided into 4 parts
    }
    else
    {
        line(x1, y1, x3, y3);
        line(x3, y3, x, y);
        line(x, y, x4, y4);
        line(x4, y4, x2, y2);
        delay(50);
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    int x1, y1, x2, y2, n;
    cout << "Enter line co-ordinates:";
    cout << "x1=";
    cin >> x1;
    cout << "y1=";
    cin >> y1;
    cout << "x2=";
    cin >> x2;
    cout << "y2=";
    cin >> y2;
    cout << "Enter number of iteration:";
    cin >> n;
    kcurve(x1, y1, x2, y2, n);
    getch();
    return 0;
}
