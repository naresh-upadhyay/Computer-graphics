#include<stdio.h>
#include<graphics.h>
#define flc(i,n,c) for(int i=0; i<n; i+=c)
int main(){
    int gd = DETECT , gm ;
    float x1 = 3 , y1 = 4 , x2 = 80 , y2 = 90;
    float dx , dy , steps , xin,yin;
    initgraph(&gd,&gm ,"");
    //setcolor(BLUE);
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    steps = dx > dy ? dx :dy;
    xin = dx/steps;
    yin = dy/steps;

    flc(i,steps,1){
        putpixel(x1,y1,GREEN);
        x1 += xin;
        y1 += yin;
    }
    delay(3000);
    closegraph();

    


}