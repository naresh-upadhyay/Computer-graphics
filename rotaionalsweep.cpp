#include <graphics.h>
#define fl(i, n) for (int i = 0; i < n; i++)
#define PI 3.142

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

void midcircle(int xc,int yc,int radious){
    int x = 0 , y = radious;
    int p0 = 1-radious;
    int pk = p0;
    while(y >= radious*cos(PI/4)-1){
        putpixel(x + xc,y + yc,GREEN);//octate 1
        putpixel(y + xc,x + yc,GREEN);//octate 2
        putpixel(y + xc,-x + yc,GREEN);//octate 3
        putpixel(x + xc,-y + yc,GREEN);//octate 4
        putpixel(-x + xc,-y + yc,GREEN);//octate 5
        putpixel(-y + xc,-x + yc,GREEN);//octate 6
        putpixel(-y + xc,x + yc,GREEN);//octate 7
        putpixel(-x + xc,y + yc,GREEN);//octate 8
        if(pk < 0){
            pk += 2*x + 3;
        }else {
            y -=1;
            pk += 2*x - 2*y + 5;
        }
        ++x;
    }
    for(int i=radious ;i>=0; i-=6){
        drawellipse(xc,yc,i,radious,GREEN);
        delay(10);
    }
    for(int i=radious ;i>=0; i-=6){
        drawellipse(xc,yc,radious,i,GREEN);
        delay(10);
    }

}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int  r=150,x=200,y=200;
    midcircle(x,y,r);
    delay(5000);
    closegraph();
}