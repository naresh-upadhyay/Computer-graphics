#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
#define fl(i, n) for (int i = 0; i < n; i++)
#define PI 3.142
//rotating the circle for creating 3d sphere
void rotations(int xx, int yy, int a, int b, int boundrycolor)
{
    int p10 = pow(b, 2) - pow(a, 2) * b + (pow(a, 2) / 2);
    int p1k1 = p10;
    int p2k1;
    int x = 0, y = b;
    while (y >= 0)
    {
        putpixel(xx + x, yy + y, boundrycolor);
        putpixel(xx + x, yy - y, boundrycolor);
        putpixel(xx - x, yy - y, boundrycolor);
        putpixel(xx - x, yy + y, boundrycolor);

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
//first draw a circle the rotate it to form shpere
void sphere(int xc, int yc, int radious)
{
    int x = 0, y = radious;
    int p0 = 1 - radious;
    int pk = p0;
    while (y >= radious * cos(PI / 4) - 1)
    {
        putpixel(x + xc, y + yc, GREEN);   //octate 1
        putpixel(y + xc, x + yc, GREEN);   //octate 2
        putpixel(y + xc, -x + yc, GREEN);  //octate 3
        putpixel(x + xc, -y + yc, GREEN);  //octate 4
        putpixel(-x + xc, -y + yc, GREEN); //octate 5
        putpixel(-y + xc, -x + yc, GREEN); //octate 6
        putpixel(-y + xc, x + yc, GREEN);  //octate 7
        putpixel(-x + xc, y + yc, GREEN);  //octate 8
        if (pk < 0)
        {
            pk += 2 * x + 3;
        }
        else
        {
            y -= 1;
            pk += 2 * x - 2 * y + 5;
        }
        ++x;
    }
    for (int i = radious; i >= 0; i -= 2)
    {
        rotations(xc, yc, i, radious, GREEN);
        //delay(10);
    }
    for (int i = radious; i >= 0; i -= 2)
    {
        rotations(xc, yc, radious, i, GREEN);
        //delay(10);
    }
}
//store all pixel of trajectory
vector<pair<int,int>> pixel;
//for inital half trajectory
void trajectoryafterhalf(int &x1, int y1, float h, float u)
{
    int g = 10, x = 0; //gravitaional acc
    float y = 0;
    while (y < h)
    {
        y = float(5 * pow(x, 2)) / pow(u, 2);
        putpixel(x1 + x, y1 + y, GREEN);
        pixel.push_back({x1 + x, y1 + y});
        x++;

    }
    x1 += x;
}//for semicircle type trajectory
void trajectorybeforehalf(int &x1, int y1, float h, float u)
{
    int g = 10, x = 0; //gravitaional acc
    float y = 0;
    while (y < h / 2 && y >= 0)
    {
        y = ((float(sqrt(h * g) * x) / u) - float(5 * pow(x, 2)) / pow(u, 2));
        putpixel(x1 + x, y1 - y, GREEN);
        pixel.push_back({x1 + x, y1 - y});
        x++;
    }
    x1 += x;
}
//draw final ball trajectory on the path
void drowball(){
    for(int i=0; i<pixel.size(); i+=25){
        sphere(pixel[i].first,pixel[i].second,15);
    }
}

int main()
{
    int gd = DETECT, gmode = 0;
    int x = 20, y = 20, h, u, t;
    cout << "Enter the value of height, speed and number of trajectorys:-";
    cin >> h >> u >> t;
    initgraph(&gd, &gmode, " ");
    trajectoryafterhalf(x, y, h, u);
    int th = h;
    //create multiple trajectoryes
    for (int i = 0; i < t; i++)
    {
        trajectorybeforehalf(x, y + th, h, u);
        h /= 2;
    }
    drowball();
    delay(10000);
    closegraph();
}