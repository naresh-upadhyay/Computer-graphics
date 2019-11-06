#include <bits/stdc++.h>
#include <graphics.h>
#define vfig vector<pair<int, int>>
#define fl(i, n) for (int i = 0; i < n; i++)
#define fln(i, n, r) for (int i = 0; i < n; i += r)
#define pi 3.14
using namespace std;
void figure(vfig vf)
{
    int i = 0;
    for (; i < vf.size()-1; i++)
    {
        line(vf[i].first, vf[i].second, vf[i + 1].first, vf[i + 1].second);
        //cout << vf[i].first<<" "<< vf[i].second<<" "<< vf[i + 1].first<<" "<< vf[i + 1].second<<endl;
    }
    line(vf[i].first, vf[i].second, vf[0].first, vf[0].second);
    //cout <<vf[i - 1].first<<" "<< vf[i - 1].second<<" " <<vf[0].first<<" "<< vf[0].second<<endl;
}
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
void newfig(int x,int y,vfig vf)
{
    float *vectmat = (float *)calloc(3, sizeof(float));
    for (int i = 0; i < vf.size(); i++)
    {
        vectmat[0] = vf[i].first;
        vectmat[1] = vf[i].second;
        vectmat[2] = 1;
        vectmat = multimatrix(translate(x, y), vectmat);
        vf[i].first = vectmat[0];
        vf[i].second = vectmat[1];
    }
    figure(vf);
    delay(500);
}
void tunnel(float x1, float y1, float x2, float y2, vfig vf)
{
    float m = (y2 - y1) / (x2 - x1);
    float c = (y1 - m * x1);

    figure(vf);
    for (int x = min(x1,x2); x < max(x1, x2); x+=3)
    {
        newfig(x,(m*x+c),vf);
    }
}
int main()
{
    int gd = DETECT, gmode = 0, nvtx;
    cout << "Enter the number of vertexes :-";
    cin >> nvtx;
    vfig vxy;
    for (int i = 0; i < nvtx; i++)
    {
        int x1, y1;
        cout << "vertex " << i + 1 << " :-" << endl;
        cin >> x1 >> y1;
        vxy.push_back({x1, y1});
    }
    int x1,y1,x2,y2;
    cout <<"vertexs of line :-";
    cin >>x1>>y1>>x2>>y2;
    initgraph(&gd, &gmode, " ");
    tunnel(x1,y1,x2,y2,vxy);
    delay(10000);
    closegraph();
}