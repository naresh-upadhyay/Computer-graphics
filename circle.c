#include<stdio.h>
#include<graphics.h>
int main(){
    int gd = DETECT , gm;
    int x = 30,y = 30 , radios = 30;
    int x1 = 30,y1 = 30, x2 = 30, y2 = 60;
    initgraph(&gd,&gm,"");
    setcolor(RED);
    circle(x,y,radios);
    setcolor(BLUE);
    line(x1,y1,x2,y2);
    delay(3000);

    closegraph();
}