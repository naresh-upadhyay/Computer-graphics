#include<stdio.h>
#include<graphics.h>
int main(){
    int gd = DETECT, gm;
    int x1 = 3,y1 = 4, x2 = 64, y2 = 34;
    initgraph(&gd,&gm,"c:\\TC\\BGI");
    setcolor(BLUE);
    line(x1,y1,x2,y2);
    delay(2000);
    closegraph();
}
//compile by gcc filename.c -o filename -lgraph
//run by ./filename
