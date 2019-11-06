#include <bits/stdc++.h>
#include <graphics.h>
#define fl(i, n) for (int i = 0; i < n; i++)
#define fln(i, n, r) for (int i = 0; i < n; i += r)
#define pi 3.14
using namespace std;
float *multimatrix(float **matrix3d, float *vectormat)
{
    float *finalmat = (float *)malloc(3 * sizeof(float));
    fl(r, 3)
    {
        float temp = 0;
        fl(c, 3)
        {
            temp += matrix3d[r][c] * vectormat[c];
        }
        finalmat[r] = temp;
    }
    return finalmat;
}
float **trans3d(float **matrix3d)
{
    float **tm3;
    tm3 = (float **)malloc(3 * sizeof(*tm3));
    fl(k, 3)
        tm3[k] = (float *)malloc(3 * sizeof(*tm3[k]));

    fl(i, 3)
    {
        fl(j, 3)
        {
            tm3[j][i] = ((matrix3d[(i + 1) % 3][(j + 1) % 3] * matrix3d[(i + 2) % 3][(j + 2) % 3]) - (matrix3d[(i + 1) % 3][(j + 2) % 3] * matrix3d[(i + 2) % 3][(j + 1) % 3]));
        }
    }
    return tm3;
}
float determ3d(float **matrix3d)
{
    return (matrix3d[0][0] * (matrix3d[1][1] * matrix3d[2][2] - matrix3d[1][2] * matrix3d[2][1]) - matrix3d[0][1] * (matrix3d[1][0] * matrix3d[2][2] - matrix3d[1][2] * matrix3d[2][0]) + matrix3d[0][2] * (matrix3d[1][0] * matrix3d[2][1] - matrix3d[1][1] * matrix3d[2][0]));
}
float **inversemat(float **matrix3d, float determinant)
{
    float d = 1 / float(determinant);
    fl(i, 3)
    {
        fl(j, 3)
        {
            matrix3d[i][j] = (float(float(matrix3d[i][j]) * d));
        }
    }
    return matrix3d;
}
float **translate(float tx, float ty)
{
    float **tm3;
    tm3 = (float **)calloc(3, sizeof(*tm3));
    fl(k, 3)
        tm3[k] = (float *)calloc(3, sizeof(*tm3[k]));
    fl(i, 3)
    {
        tm3[i][i] = 1;
    }
    tm3[0][2] = tx;
    tm3[1][2] = ty;
    return tm3;
}
float **scaling(float sx, float sy)
{
    float **tm3;
    tm3 = (float **)calloc(3, sizeof(*tm3));
    fl(k, 3)
        tm3[k] = (float *)calloc(3, sizeof(*tm3[k]));
    tm3[0][0] = sx;
    tm3[1][1] = sy;
    tm3[2][2] = 1;
    return tm3;
}
float **Rotation(float theta)
{
    float **tm3;
    tm3 = (float **)calloc(3, sizeof(*tm3));
    fl(k, 3)
        tm3[k] = (float *)calloc(3, sizeof(*tm3[k]));
    tm3[0][0] = cos(theta * (pi / 180));
    tm3[1][1] = cos(theta * (pi / 180));
    tm3[0][1] = -sin(theta * (pi / 180));
    tm3[1][0] = sin(theta * (pi / 180));
    tm3[2][2] = 1;
    return tm3;
}
void floodfill(int x,int y,int newcolor,int oldcolor){
    int color = getpixel(x,y);
    if(color == oldcolor){
        putpixel(x,y,newcolor);
        floodfill(x+1,y,newcolor,oldcolor);
        floodfill(x,y+1,newcolor,oldcolor);
        floodfill(x,y-1,newcolor,oldcolor);
        floodfill(x-1,y,newcolor,oldcolor);
    }
}
int main()
{
    int gd = DETECT, gmod = 0, far = 20;
    initgraph(&gd, &gd, "");
    float *xycor;
    xycor = (float *)calloc(3, sizeof(float));
    vector<pair<int, int>> arr;
    arr.push_back({0, 0});
    arr.push_back({0, 1});
    arr.push_back({1, 1});
    arr.push_back({1, 0});
    fl(i, 2)
    {
        fl(j, 2)
        {

            xycor[0] = arr[(i*2+j)%4].first * 50;
            xycor[1] =  arr[(i*2+j)%4].second * 50;
            xycor[2] = 1;
            xycor = multimatrix(translate(50,50),multimatrix(Rotation(-45), multimatrix(scaling(1, 2), multimatrix(Rotation(45), xycor))));
            arr[(i*2+j)%4].first = round(xycor[0]);
            arr[(i*2+j)%4].second = round(xycor[1]);
        }
    }
    fl(i,2){
        fl(j,2){
            //cout<<arr[(i*2+j)%4].first<<" "<<arr[(i*2+j)%4].second<<" "<<arr[(i*2+j+1)%4].first<<" "<<arr[(i*2+j+1)%4].second<<endl;
            line(arr[(i*2+j)%4].first,arr[(i*2+j)%4].second,arr[(i*2+j+1)%4].first,arr[(i*2+j+1)%4].second);
        }
    }
    floodfill(far+52,far+52,GREEN,getpixel(far+52,far+52));
    delay(10000);
    closegraph();
}