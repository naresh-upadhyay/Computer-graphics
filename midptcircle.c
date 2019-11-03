#include <graphics.h>
#define fl(i, n) for (int i = 0; i < n; i++)
#define PI 3.142
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
        delay(50);
    }

}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int  r=50,x=60,y=70;
    midcircle(x,y,r);
    delay(5000);
    closegraph();
}