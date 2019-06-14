#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
int a[10][10];

int color(int x, int y,int k,int old,int p,int q)
{
    if (x>=0 && y>=0 && x<p && y<q)
    {
    if (a[x][y]!=old)
        return 0;

    a[x][y]=k;

    color (x+1,y,k,old,p,q);
    color (x-1,y,k,old,p,q);
    color (x,y+1,k,old,p,q);
    color (x,y-1,k,old,p,q);
    }

    return 0;
}

int main ()
{

    int p,q;
    cin >> p >> q;
    //int a[n][m];
    int i,j;

    for (i=0;i<10;i++)
    {
        for (j=0;j<10;j++)
            a[i][j]=0;
    }
 int x,y,k,ol;
    for (i=0;i<p;i++)
    {
        for (j=0;j<q;j++)
            cin >> a[i][j];
    }

    cin >> x >> y >> k;
    ol = a[x][y];


    color(x,y,k,ol,p,q);

    for (i=0;i<p;i++)
    {
        for (j=0;j<q;j++)
            cout << a[i][j] << " ";
    }


}
