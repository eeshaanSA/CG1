#include <iostream>
using namespace std;
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>
int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
int xmax, xmin, ymax, ymin;
int getcode(int x, int y) // to tell the endpoints
{
    int code = 0;
    if (y > ymax)
        code |= TOP;
    if (y < ymin)
        code |= BOTTOM;
    if (x > xmax)
        code |= RIGHT;
    if (x < xmin)
        code |= LEFT;
    return code;
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    cout << "Enter the window co-ordinates:\n";
    cout << "Xmin=";
    cin >> xmin;
    cout << "Ymin=";
    cin >> ymin;
    cout << "Xmax=";
    cin >> xmax;
    cout << "Ymax=";
    cin >> ymax; // to create the window for clipping
    rectangle(xmin, ymin, xmax, ymax);
    int x1, y1, x2, y2;
    cout << "Enter line co-ordinates:\n";
    cout << "x1=";
    cin >> x1;
    cout << "y1=";
    cin >> y1;
    cout << "x2=";
    cin >> x2;
    cout << "y2=";
    cin >> y2;
    line(x1, y1, x2, y2);
    int outcode1 = getcode(x1, y1), outcode2 = getcode(x2, y2); // to generate the codes of endpts of line
    cout << outcode1 << endl;
    cout << outcode2 << endl; // mistake was here
    int accept = 0;
    while (1) // the condition is true
    {
        float m = (float)(y2 - y1) / (x2 - x1);
        if (outcode1 == 0 && outcode2 == 0) // check using conditional operator
        {
            accept = 1; // if true accept the line completely
            break;
        }
        else if ((outcode1 & outcode2) != 0) // check using bitwise & operator
        {
            break; // reject the line
        }
        else
        {
            int x, y, temp;
            if (outcode1 == 0)
                temp = outcode2;
            else
                temp = outcode1;
            if (temp & TOP) // check bitwise and of these, if true then perfom following
            {
                x = x1 + (ymax - y1) / m; // intersection with top boundary
                y = ymax;                 // since on the entire top boundary y=ymax
            }
            else if (temp & BOTTOM)
            {
                x = x1 + (ymin - y1) / m; // intersection with bottom
                y = ymin;
            }
            else if (temp & LEFT)
            {
                x = xmin;
                y = y1 + m * (xmin - x1);
            }
            else if (temp & RIGHT)
            {
                x = xmax;
                y = y1 + m * (xmax - x1);
            }
            if (temp == outcode1)
            {
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1, y1); // change the values of x1 and y1
            }
            else
            {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2, y2);
            }
        }
    }
    if (accept)
    {
        cout << "line accepted";
        cleardevice();
        rectangle(xmin, ymin, xmax, ymax);
        setcolor(YELLOW);
        line(x1, y1, x2, y2);
    }
    else
    {
        cout << "line rejected";
    }
    getch();
    closegraph();
}
