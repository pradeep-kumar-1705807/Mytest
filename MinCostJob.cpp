#include<bits/stdc++.h>
using namespace std;
#define D 4
int minCost(int cost[D][D], int n, int p, int mask) 
{
    if(p>=n)
    {
        return 0;
    }
    int minimum=99999999;
    for(int j=0;j<n;j++)
    {
        if((mask & (1<<j))==0)
        {
            int ans=cost[p][j]+minCost(cost,n,p+1,mask|(1<<j));
            if(ans<minimum)
            {
                minimum=ans;
            }
        }
    }
    return minimum;
}
int main()
{
    int n;
    cin>>n;
    int cost[D][D];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>cost[i][j];
        }
    }
    cout<<minCost(cost,n,0,0);
    return 0;
}

/*
Test Case
4
10 2 6 5
1 15 12 8
7 8 9 3
15 13 4 10
*/