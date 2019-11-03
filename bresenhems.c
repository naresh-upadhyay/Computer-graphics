//gcc bresenhems.c -lgraph
#include<stdio.h>
#include<graphics.h>
void breshline(int x1,int y1,int x2,int y2){
    int dx = x2 - x1 , dy = y2 - y1;
    int p = 2*dy - dx;
    int x = x1,y = y2;
    while(x <= x2){
        putpixel(x,y,GREEN);
        if(p < 0){
            p = p + 2*dy;
            x++;
        }else{
            p = p + 2*dy - 2*dx;
            x++;
            y++;
        }
    }
}
int main(){
    int gd = DETECT , gm;
    int x1=2,y1=3,x2=300,y2=150;
    initgraph(&gd , &gm ,"");
    breshline(x1,y1,x2,y2);
    delay(3000);
    closegraph();

}