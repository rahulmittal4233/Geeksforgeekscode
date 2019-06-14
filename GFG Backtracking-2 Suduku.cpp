#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;
int a[9][9];

void build ()
{
    for (int i=0;i<9;i++)
        for (int j=0;j<9;j++)
            cin >> a[i][j];
}

void output ()
{
    for (int i=0;i<9;i++)
     {
        for (int j=0;j<9;j++)
            cout << a[i][j];
     cout << endl;
     }
}

bool checkinnercol(int x,int y)
{
    int r=(x/3)*3;
    int c=(y/3)*3;

    for (int i=r;i<(r+3);i++)
        for (int j=c;j<(c+3);j++)
            if (a[i][j]==a[x][y] && x!=i && y!=j)
                    return false;
    return true;
}

bool usedincol(int x, int y)
{
    for (int i=0;i<9;i++)
        if (a[i][y]==a[x][y] && i!=x)
            return false;
    return true;
}

bool usedinrow(int x, int y)
{
    for (int i=0;i<9;i++)
        if (a[x][i]==a[x][y] && i!=y)
            return false;
    return true;
}

bool findempty(int &row, int &col) // & means address i.e empty row,col pair is found and the variables are declared in fn from where this function is being called
{
      for (row=0;row<9;row++)
        for (col=0;col<9;col++)
            if (a[row][col]==0)
                return false;
    return true;
}

bool solvesuduku() //IMPORTANT
{
    int row, col;
    if (findempty(row,col))
        return true;

    for (int k=1;k<=9;k++)  // note the flow of code.
    {
        a[row][col]=k;
      //  cout << a[row][col]<< endl;
        if ( checkinnercol(row,col) && usedincol(row,col) && usedinrow(row,col) )
            if (solvesuduku())
                return true;
        a[row][col]=0;
    }
return false;
}

int main ()
{
    build();

    solvesuduku();

    output();
}
