#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

struct order
{
    int id;
    int rt;
    int n;
    int d;
    int l;
};

int compare(const void *a, const void *b)
{
    order x = *(order *)a;
    order y = *(order *)b;

    if(x.rt<y.rt)
        return -1;
    else if(x.rt>y.rt)
        return 1;
    if(x.rt==y.rt && x.l>y.l)
    {
        return -1;
    }
    if(x.rt==y.rt && x.l<y.l)
        return 1;
    return 0;


}


void warehousemanagement()
{
    int t;
    cin>>t;
    int n;

    while(t--)
    {
        cin>>n;
        order ord[n];
        int p,q,r,s,t;
        int mi,ma;
        mi = INT_MAX;
        ma = INT_MIN;
        map<int,int>m,u;
        for(int i =0;i<n;i++)
        {
            cin>>p>>q>>r>>s>>t;
            mi = min(mi,q);
            ma = max(ma,s);
            ord[i].id = p;
            ord[i].rt = q;
            ord[i].n = r;
            ord[i].d = s;
            ord[i].l = t;

            m[p] = r;
            u[p] = t;
        }
//        cout<<endl;
//        cout<<ma<<endl<<mi<<endl;

        qsort(ord,n,sizeof(ord[0]),compare);


//        for(int i =0;i<n;i++)
//        {
//            cout<<ord[i].id<<" "<<ord[i].rt<<" "<<ord[i].n<<" "<<ord[i].d<<" "<<ord[i].l<<endl;
//        }

        map<int,int>::iterator i;

//        for(i = m.begin();i!=m.end();i++)
//        {
//            cout<<i->first<<" "<<i->second<<endl;
//        }

        for(int i = mi;i<ma;i++)
        {

            for(int j =0;j<n;j++)
            {
                if(i>=ord[j].rt && m[ord[j].id]>0 && i<ord[j].d)
                {
                    m[ord[j].id]--;
                    break;
                }
            }
        }



//        for(i = m.begin();i!=m.end();i++)
//        {
//            cout<<i->first<<" "<<i->second<<endl;
//        }
//        cout<<endl;
        long long loss = 0;
        for(i = m.begin();i!=m.end();i++)
        {
            if(i->second>0)

                loss += (i->second)* u[i->first];
        }

        cout<<loss<<endl;
    }
}


int main()
{
    //warehousemanagement();


    return 0;
}

