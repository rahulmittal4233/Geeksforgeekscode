#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main ()
{
    int x,y,i,j;
    cin >> x >> y;
    int a[x][y];

    for (i=0;i<x;i++)
        for (j=0;j<y;j++)
            a[i][j]=0;

    for (i=0;i<x;i++)
        a[i][0]=1;

    for (i=0;i<y;i++)
        a[0][i]=1;

    for (i=1;i<x;i++)
        for (j=1;j<y;j++)
         {

         a[i][j]=a[i-1][j] + a[i][j-1];
     //    cout << a[i][j] << " ";
         }
    cout << a[x-1][y-1] << endl;
    return 0;
}
