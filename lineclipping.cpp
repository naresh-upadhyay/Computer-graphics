#include <bits/stdc++.h>
#include <graphics.h>
#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8
using namespace std;
int minx = 40, miny = 40, maxx = 120, maxy = 120;
int codeforloc(int x, int y)
{
    int code = INSIDE;
    if (x < minx)
    {
        code |= LEFT;
    }
    else if (x > maxx)
    {
        code |= RIGHT;
    }
    if (y < miny)
    {
        code |= BOTTOM;
    }
    else if (y > maxy)
    {
        code |= TOP;
    }
    return code;
}
void cutting(float x1, float y1, float x2, float y2)
{
    setcolor(BLUE);
    line(x1, y1, x2, y2);
    bool accepted = false;
    int code1 = codeforloc(x1, y1);
    int code2 = codeforloc(x2, y2);
    while (1)
    {
        if (code1 == 0 && code2 == 0)
        {
            accepted = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int newcode;
            float x,y;
            if (code1 != 0)
            {
                newcode = code1;
            }
            else
            {
                newcode = code2;
            }
			if (newcode & TOP) 
			{ 
				x = x1 + (x2 - x1) * (maxy - y1) / (y2 - y1); 
				y = maxy; 
			} 
			else if (newcode & BOTTOM) 
			{ 
				x = x1 + (x2 - x1) * (miny - y1) / (y2 - y1); 
				y = miny; 
			} 
			else if (newcode & RIGHT) 
			{ 
				y = y1 + (y2 - y1) * (maxx - x1) / (x2 - x1); 
				x = maxx; 
			} 
			else if (newcode & LEFT) 
			{ 
				y = y1 + (y2 - y1) * (minx - x1) / (x2 - x1); 
				x = minx; 
			} 

			if (newcode == code1) 
			{ 
				x1 = x; 
				y1 = y; 
				code1 = codeforloc(x1, y1); 
			} 
			else
			{ 
				x2 = x; 
				y2 = y; 
				code2 = codeforloc(x2, y2); 
			} 
        }
    }

    if (accepted)
    {
        cout << "Line accepted from " << x1 << ", "
             << y1 << " to " << x2 << ", " << y2 << endl;
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    }
    else
    {
        cout << "Line rejected" << x1 << ", "
             << y1 << " to " << x2 << ", " << y2 << endl;
        
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}
void frame(int minx, int miny, int maxx, int maxy)
{
    line(minx, miny, maxx, miny);
    line(minx, miny, minx, maxy);
    line(maxx, miny, maxx, maxy);
    line(maxx, maxy, minx, maxy);
}
int main()
{
    int gd = DETECT, gmode = 0, nlines;
    cout << "Enter the number of lines :-";
    cin >> nlines;
    vector<pair<int, int>> vxy;
    for (int i = 0; i < nlines; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        vxy.push_back({x1, y1});
        vxy.push_back({x2, y2});
    }
    initgraph(&gd, &gmode, " ");
    int zoom = 10;
    frame(minx, miny, maxx, maxy);
    for (int j = 0; j < vxy.size(); j += 2)
    {
        cout << vxy[j].first * zoom << " " << vxy[j].second * zoom << " " << vxy[j + 1].first * zoom << " " << vxy[j + 1].second * zoom << endl;
        cutting(vxy[j].first * zoom, vxy[j].second * zoom, vxy[j + 1].first * zoom, vxy[j + 1].second * zoom);
    }
    delay(10000);
    closegraph();
} /*
1 3 17 13 
0 6 8 3
4 3 13 11
4 8 13 16
*/