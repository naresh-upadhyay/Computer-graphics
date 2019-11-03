#include <bits/stdc++.h>
#include <graphics.h>
#define mp map<int, vector<int>>
using namespace std;
void scanlinefill(mp mfill)
{
    for (auto it = mfill.begin(); it != mfill.end(); it++)
    {
        for (auto it1 = (it->second).begin(); it1 != (it->second).end(); it1 += 2)
        {
            setcolor(RED);
            line((*it1), it->first, (*(it1 + 1)), it->first);
            delay(100);
        }
    }
}
mp polygoncoordinates(vector<pair<float, float>> cordinates)
{
    mp ytox;
    int ncord = cordinates.size();
    int i = 0, j = 1, k = 2;
    while (1)
    {
        if (cordinates[j].second < cordinates[k].second && cordinates[j].second > cordinates[i].second)
        {
            pair<float, float> a = cordinates[i], b;
            float ibym = (cordinates[i].first - cordinates[j].first) / (cordinates[i].second - cordinates[j].second);
            b.second = cordinates[j].second - 1;
            float newx = a.first;

            for (int ii = a.second; ii <= b.second; ii++)
            {
                ytox[ii].push_back(newx);
                newx += ibym;
            }
        }
        else if (cordinates[j].second > cordinates[k].second && cordinates[j].second < cordinates[i].second)
        {
            pair<float, float> a = cordinates[i], b;
            float ibym = (cordinates[i].first - cordinates[j].first) / (cordinates[i].second - cordinates[j].second);
            b.second = cordinates[j].second;
            float newx = a.first;

            for (int ii = a.second; ii >= b.second; ii--)
            {
                ytox[ii].push_back(newx);
                newx -= ibym;
            }
            float ibym2 = (cordinates[k].first - cordinates[j].first) / (cordinates[k].second - cordinates[j].second);

            cordinates[j].second -= 1;
            cordinates[j].first -= ibym2;
        }
        else if (cordinates[j].second > cordinates[k].second && cordinates[j].second > cordinates[i].second)
        {
            pair<float, float> a = cordinates[i], b;
            float ibym = (cordinates[i].first - cordinates[j].first) / (cordinates[i].second - cordinates[j].second);
            b.second = cordinates[j].second;
            float newx = a.first;

            for (int ii = a.second; ii <= b.second; ii++)
            {
                ytox[ii].push_back(newx);
                newx += ibym;
            }
        }
        else
        {
            pair<float, float> a = cordinates[i], b;
            float ibym = (cordinates[i].first - cordinates[j].first) / (cordinates[i].second - cordinates[j].second);
            b.second = cordinates[j].second;
            float newx = a.first;

            for (int ii = a.second; ii >= b.second; ii--)
            {
                ytox[ii].push_back(newx);
                newx -= ibym;
            }
        }
        i = (i + 1) % ncord;
        j = (j + 1) % ncord;
        k = (k + 1) % ncord;
        if (j == 1)
            break;
    }
    for (auto it = ytox.begin(); it != ytox.end(); it++)
    {
        sort((it->second).begin(), (it->second).end());
    }
    return ytox;
}
void polygon(vector<pair<float, float>> cordinates)
{
    int sz = cordinates.size();
    for (int i = 0; i < sz; i++)
    {
        line((cordinates[i]).first,(cordinates[i]).second,(cordinates[(i+1)%sz]).first,((cordinates[(i+1)%sz]).second));
    }
    scanlinefill(polygoncoordinates(cordinates));
}
int main()
{
    vector<pair<float, float>> coordinates;
    int ncord;
    cout << "No of coordinates :-";
    cin >> ncord;
    for (int a = 0; a < ncord; a++)
    {
        float x, y;
        cout << "c" << (1 + a) << ":-";
        cin >> x >> y;
        coordinates.push_back({x, y});
    }

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    polygon(coordinates);
    delay(3000);
    closegraph();
}