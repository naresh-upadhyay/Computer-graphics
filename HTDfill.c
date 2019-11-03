#include<graphics.h>
#define PI 3.142

int h1=100,h2=10,w1=30;//w1 = 3 * h2 & h1 = 10 * h2
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
void hcornertop(int x,int y, int color){
    setcolor(color);
    line(x+h2,y+h2,x+0,y+h2);
    line(x+0,y+h2,x+0,y+0);
    line(x+0,y+0,x+w1,y+0);
    line(x+w1,y+0,x+w1,y+h2);
    line(x+w1,y+h2,x+(w1-h2),y+h2);
}
void tcornertop(int x,int y, int color){
    setcolor(color);
    line(x+4*h2,y+h2,x+0,y+h2);
    line(x+0,y+h2,x+0,y+0);
    line(x+0,y+0,x+3*w1,y+0);
    line(x+3*w1,y+0,x+3*w1,y+h2);
    line(x+3*w1,y+h2,x+5*h2,y+h2);
}
void hcornerdown(int x,int y, int color){
    setcolor(color);
    line(x+(w1-h2),y+0,x+w1,y+0);
    line(x+w1,y+0,x+w1,y+h2);
    line(x+w1,y+h2,x+0,y+h2);
    line(x+0,y+h2,x+0,y+0);
    line(x+0,y+0,x+h2,y+0);
}
void hformation(int x , int y , int color,int fillcolor){
    setcolor(color);
    line(x+h2,y+h2,x+h2,y+h2+h1);
    line(x+2*h2,y+h2,x+2*h2,y+5*h2);
    line(x+2*h2,y+5*h2,x+2*h2+2*w1,y+5*h2);
    line(x+2*h2+2*w1,y+5*h2,x+2*h2+2*w1,y+h2);
    line(x+3*w1,y+h2,x+3*w1,y+h2+h1);
    line(x+3*w1-h2,y+h2+h1,x+3*w1-h2,y+7*h2);
    line(x+3*w1-h2,y+7*h2,x+2*h2,y+7*h2);
    line(x+2*h2,y+7*h2,x+2*h2,y+h1+h2);
    hcornertop(x,y,color);
    hcornertop(x+2*w1+h2,y,color);
    hcornerdown(x,y+h1+h2,color);
    hcornerdown(x+2*w1+h2,y+h1+h2,color);
    boundryfill4(x+1,y+1,color,fillcolor);
}
void tformation(int x,int y, int color,int newcolor){
    setcolor(color);
    tcornertop(x,y,color);
    line(x+4*h2,y+h2,x+4*h2,y+h1+h2);
    line(x+5*h2,y+h2,x+5*h2,y+h1+h2);
    hcornerdown(x+3*h2,y+h1+h2,color);
    boundryfill4(x+1,y+1,color,newcolor);
}
void midcircle(int xc,int yc,int radious,int color){
    int x = 0 , y = radious;
    int p0 = 1-radious;
    int pk = p0;
    while(y >= radious*cos(PI/4)-1){
        putpixel(x + xc,y + yc,color);//octate 1
        putpixel(y + xc,x + yc,color);//octate 2
        putpixel(y + xc,-x + yc,color);//octate 3
        putpixel(x + xc,-y + yc,color);//octate 4
        if(pk < 0){
            pk += 2*x + 3;
        }else {
            y -=1;
            pk += 2*x - 2*y + 5;
        }
        ++x;
        //delay(50);
    }

}
void Dformation(int x,int y , int boundary,int fillcolor){
    line(x+h2,y+0,x+0,y+0);
    line(x+0,y+0,x+0,y+h1+2*h2);
    line(x+0,y+h1+2*h2,x+h2,y+h1+2*h2);
    line(x+h2,y+h2,x+h2,y+h1+h2);
    midcircle(x+h2,y+h2+(h1/2),(h1/2),boundary);
    midcircle(x+h2,y+h2+(h1/2),(h1/2)+h2,boundary);
    boundryfill4(x+1,y+1,boundary,fillcolor);
}
int main(){
    int gd = DETECT , gm;
    initgraph(&gd,&gm,"");
    hformation(4,4,RED,GREEN);
    tformation(150,4,RED,GREEN);
    Dformation(300,4,RED,GREEN);
    delay(5000);
    closegraph();
}