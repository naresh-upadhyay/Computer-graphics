#include <bits/stdc++.h>
#include <graphics.h>
void boundryfill4(int x,int y ,int boundrycolor,int fillcolor){
    int pixelcolor = getpixel(x,y);
    if(pixelcolor != fillcolor && boundrycolor != pixelcolor){
        putpixel(x,y,fillcolor);
        boundryfill4(x-1,y,boundrycolor,fillcolor);
        boundryfill4(x+1,y,boundrycolor,fillcolor);
        boundryfill4(x,y+1,boundrycolor,fillcolor);
        boundryfill4(x,y-1,boundrycolor,fillcolor);
    }
}

void drawellipse(int xx, int yy, int a, int b, int boundrycolor)
{
    int p10 = pow(b, 2) - pow(a, 2) * b + (pow(a, 2) / 2);
    int p1k1 = p10;
    int p2k1;
    int x = 0,y=b;
    while (y >= 0)
    {
        putpixel(xx+x, yy+y, boundrycolor);
        putpixel(xx+x, yy-y, boundrycolor);
        putpixel(xx-x, yy-y, boundrycolor);
        putpixel(xx-x, yy+y, boundrycolor);

        if ((pow(b, 2) * x) < (pow(a, 2) * y))
        {
            if (p1k1 < 0)
            {
                p1k1 += 2 * pow(b, 2) * (x + 1) + pow(b, 2);
                x++;
            }
            else
            {
                p1k1 += 2 * pow(b, 2) * (x + 1) + pow(b, 2) - 2 * pow(a, 2) * (y - 1);
                x++;
                y--;
            }
            p2k1 = pow(b, 2) * pow((x + (1 / 2)), 2) + pow(a, 2) * pow((y - 1), 2) - pow(a, 2) * pow(b, 2);
        }
        else
        {
            if (p2k1 > 0)
            {
                p2k1 += -2 * pow(a, 2) * (y - 1) + pow(a, 2);
                y--;
            }
            else
            {
                p2k1 += 2 * pow(b, 2) * (x + 1) + pow(a, 2) - 2 * pow(a, 2) * (y - 1);
                x++;
                y--;
            }
        }
    }
}
int main()
{
    int gm = DETECT, gd;
    initgraph(&gm, &gd, " ");
    int xc = 100,yc=100;
    drawellipse(xc,yc, 50, 70, RED);
    drawellipse(xc,yc, 40, 60, RED);
    boundryfill4(xc+41,yc,RED,GREEN);
    delay(2000);
    closegraph();
}