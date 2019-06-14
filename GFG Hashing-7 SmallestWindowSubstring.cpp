#include <stdlib.h>
#include<map>
#include <vector>
#include<string.h>
#include <iostream>

using namespace std;

void finpair (string a, int *c, map<int, pair <int,int> > &m /*IMPORTANT*/, int st, int sz )
{
    int coun=0;
    for (int i=st; i<a.size();i++)
    {
        if (c[a[i]]>0);
            coun++;
        if (coun==sz)
        {
            m[i-st]= make_pair(st,i);
            break;
        }
    }
}

int main ()
{
    string a,b;
    cin >> a ;
    cin >> b;
    int i,j,k,c[150];
    map <int, pair<int,int> > m;

    for (i=0;i<150;i++)
        c[i]=0;

    j = b.size();
    cout <<j << endl;
    for (i=0;i<b.size();i++)
        c[b[i]]++;

    for (i=0;i<a.size();i++)
    {
        if (c[a[i]]>0)
            finpair(a,c,m,i,j);
    }

    map <int, pair<int,int> > ::iterator it;

    for (it=m.begin();it!=m.end();it++)
    {
        pair<int,int> p;
        p = it->second;
        for (i=p.first;i<=p.second;i++)
            cout<< a[i];
    }
    cout<< endl;

    return 0;
}
