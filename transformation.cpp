#include <stdio.h>
#include <iostream>
#include <math.h>
#include <dos.h>
#include <graphics.h>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    int i, j, k, sx, sy, ch, tx, ty, b, x, n;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int xa, ya, xb, yb, xc, yc, xd, yd;
    int s[3][3], a1[4][3], t[3][3];
    float r[3][3];
    cout << "Enter the no. of vertices of polygon : ";
    cin >> n;
    int a[n][3];
    for (i = 0; i < n; i++)
    {
        a[i][2] = 1;
    }
    for (i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << "th co-ordinate :";
        cin >> a[i][0] >> a[i][1];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    for (i = 0; i < n - 1; i++)
    {
        line(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
    }
    line(a[n - 1][0], a[n - 1][1], a[0][0], a[0][1]);
    do
    {

        cout << "\nSELECT";
        cout << "\n1)SCALING"
                "\n2)TRANSLATION"
                "\n3)ROTATION"
                "\n4)EXIT";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nScaling Operation:\n";
            cout << "Enter scaling co ord:";
            cout << "\nsx=";
            cin >> sx;
            cout << "\nsy=";
            cin >> sy;

            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    s[i][j] = 0;
                }
                s[0][0] = sx;
                s[1][1] = sy;
                s[2][2] = 1;
            };
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {

                    cout << s[i][j] << "\t";
                }
                cout << "\n";
            }
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    a1[i][j] = 0;
                }
            };
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    for (k = 0; k < 3; k++)
                    {
                        a1[i][j] += a[i][k] * s[k][j];
                    }
                }
            }

            for (i = 0; i < 4; i++)
                for (j = 0; j < 3; j++)
                {
                    cout << " " << a1[i][j];
                    if (j == 2)
                        cout << endl;
                }
            line(a1[0][0], a1[0][1], a1[1][0], a1[1][1]);
            line(a1[1][0], a1[1][1], a1[2][0], a1[2][1]);
            line(a1[2][0], a1[2][1], a1[3][0], a1[3][1]);
            line(a1[3][0], a1[3][1], a1[0][0], a1[0][1]);
            break;
        case 2:
            cout << "\nTranslation operation:";
            cout << "\nEnter translating co-ords";
            cout << "\ntx=";
            cin >> tx;
            cout << "\nty=";
            cin >> ty;
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    t[i][j] = 0;
                }
                t[2][0] = tx;
                t[2][1] = ty;
                t[2][2] = t[1][1] = t[0][0] = 1;
            };
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {

                    cout << t[i][j] << "\t";
                }
                cout << "\n";
            }
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    a1[i][j] = 0;
                }
            };
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    for (k = 0; k < 3; k++)
                    {
                        a1[i][j] += a[i][k] * t[k][j];
                    }
                }
            }

            for (i = 0; i < 4; i++)
                for (j = 0; j < 3; j++)
                {
                    cout << " " << a1[i][j];
                    if (j == 2)
                        cout << endl;
                }
            line(a1[0][0], a1[0][1], a1[1][0], a1[1][1]);
            line(a1[1][0], a1[1][1], a1[2][0], a1[2][1]);
            line(a1[2][0], a1[2][1], a1[3][0], a1[3][1]);
            line(a1[3][0], a1[3][1], a1[0][0], a1[0][1]);
            break;
        case 3:
            cout << "Enter angle:";
            cin >> b;
            float z;
            z = (b * 3.14 / 180);

            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    r[i][j] = 0;
                }
            }
            r[0][0] = cos(z);
            r[0][1] = sin(z);
            r[1][0] = -sin(z);
            r[1][1] = cos(z);
            r[2][2] = 1;
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {

                    cout << r[i][j] << "\t";
                }
                cout << "\n";
            }
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    a1[i][j] = 0;
                }
            };
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    for (k = 0; k < 3; k++)
                    {
                        a1[i][j] += a[i][k] * r[k][j];
                    }
                }
            }

            for (i = 0; i < 4; i++)
                for (j = 0; j < 3; j++)
                {
                    cout << " " << a1[i][j];
                    if (j == 2)
                        cout << endl;
                }
            line(a1[0][0], a1[0][1], a1[1][0], a1[1][1]);
            line(a1[1][0], a1[1][1], a1[2][0], a1[2][1]);
            line(a1[2][0], a1[2][1], a1[3][0], a1[3][1]);
            line(a1[3][0], a1[3][1], a1[0][0], a1[0][1]);
            break;
        case 4:
            exit(0);
        }
    } while (1);
    getch();
}
