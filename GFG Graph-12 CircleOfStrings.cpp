#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

vector < vector <int> > g;
vector <bool> vis;

void dfs(int k)
{
    vis[k]=true;
    for (int i=0;i<g[k].size();i++)
    {
        if (!vis[g[k][i]])
            dfs(g[k][i]);
    }
}

int main()
{
    int n,t,ans=0;
    string w;
    vector <string> words;
    cin >> n;
    vector <int> in;
    vector <int> out;
    in.assign(30,0);
    out.assign(30,0);
    g.assign(30, vector <int> () );

    for (int i=0;i<n;i++)
    {
        cin >> w;
        words.push_back(w);
        t=w[0]-'a';
        out[t]++;
    //  cout <<t;
        t=w[w.size()-1]-'a';
        in[t]++;
      //  cout <<t;
    }

    for (int i=0;i<=26;i++)  //Checking that in-degree and Out-degree are same
    {
        if (in[i]!=out[i])
        {
            cout << "Circle is Not Possible" << endl;
            ans = 1; break;
        }
        else
            continue;
    }
    int a,b,s,flag=-1;

    for (int i=0;i<words.size();i++)  //This creates a graph
    {
        a=words[i][0]-'a';
        s=words[i].size();
        b=words[i][s-1]-'a';
        g[a].push_back(b);
    }

    vis.assign(30,false);
    int p;
    for (p=0;p<30;p++)  //dfs IS executed for any character which is first ch. in a string
    {
        if (g[p].size())
            break;
    }
    dfs(p);

    for (int i=0;i<30;i++)
    {
        if (g[i].size())
        {
            if (vis[i]==false)
             {
                 flag=0;
                 break;
             }

        }
        flag=1;
    }

    if (ans==1 || flag==0)
        cout << "Circle is not possible" << endl;

    if (flag==1)
        cout << "Circle is possible" << endl;

    return 0;
}
