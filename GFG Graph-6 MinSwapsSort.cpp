#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int minswaps(vector <int> v)
{
    int n=v.size();
    pair<int,int>  a[n];  //Have pair's array and not vector of pairs as sort function works on pair's array and not vector of pairs

    for (int i=0;i<n;i++)
    {
     a[i].first = v[i];
     a[i].second = i;
    }

    sort(a,a+n);
   /* pair <int,int> it;
    for (int i=0;i<n;i++)
    {
//        it=a[i];
 //    cout << it.first << " " << it.second << endl; //a.push_back(make_pair(v[i],i));
    } */
    int ans=0,csize,j;
    vector <bool> vis;
    vis.assign(n,false);

    for (int i=0;i<n;i++)
    {
        if (vis[i]==true || a[i].second == i) //i.e is not visited and not in already sorted place
            continue;
        csize=0; j=i;
        while ( vis[j]!=true)
        {
            vis[j]=true;
            j=a[j].second;
            csize++;
        }
        if (csize>0)
            ans+=csize-1;

    }

    return ans;
}


int main()
{
    int n,t;
    vector <int> v;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> t;
        v.push_back(t);
    }

    int ans = minswaps(v);
    cout << "Minimum swaps required are: " << ans << endl;

    return 0;
}
