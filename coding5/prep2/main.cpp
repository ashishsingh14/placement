#include <iostream>
#include <bits/stdc++.h>
#include <set>
using namespace std;
struct point {

    int xp;
    int yp;
};
int main()
{


    set<point> s;
    point p1;
    p1.xp = 2;
    p1.yp = 4;
    point p2;
    p2.xp = 5;
    p2.yp = 9;
    s.insert(p1);
    //s.insert(p2);

    set<point>::iterator it;
    //it = s.find(p2);
    //cout<<(*it).xp<<endl<<(*it).yp<<endl;
    return 0;
}

