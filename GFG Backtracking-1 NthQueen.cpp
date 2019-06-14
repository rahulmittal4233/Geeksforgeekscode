#include <stdio.h>
#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int a[11][11];

void build (int n)
{
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            a[i][j]=0;
}
bool issafe(int r, int c, int n) //Should be correct, give special care
{
    for (int i=c;i>=0;i--)  //Checks for Queens lying in same row
        if (a[r][i])
            return false;

    for (int i=c,j=r;i>=0 && j>=0;i--,j--) // checks for queens lying in diagonally upper row
        if (a[j][i])
            return false;

    for (int i=r,j=c;i<n && j>=0;i++,j--) // checks for queens lying in diagonally lower row
        if (a[i][j])
            return false;
}

void printsol(int n)
{
    cout <<"[";
    for (int j=0;j<n;j++)
    {    for (int i=0;i<n;i++)
        {   if (a[i][j])
            {
            cout <<i+1<<" ";   //prints the row number having Queen for jth column
            break;    //breaks inner loop while outer loop is still running
            }
        }
    }
    cout <<"] " << endl;
}

void solve(int c, int n)
{
    if (c==n) //i.e all the columns have been done
        printsol(n);

    for (int i=0;i<n;i++)
    {
        if (issafe(i,c,n))   //checks for all rows (ith) for Cth column
        {
            a[i][c]=1;
            solve(c+1,n); //checks for next column now
            a[i][c]=0; //turns back 0 as if solution would have existed it would have been printed by now
        }
    }

}

int main()
{
    int n;
    cin >> n;
    build(n); //Initializes array to 0

    solve(0,n);

    return 0;
}
