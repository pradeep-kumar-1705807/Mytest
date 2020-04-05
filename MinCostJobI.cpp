#include<bits/stdc++.h>
using namespace std;
#define D 4
int countSetBits(int n)
{
    int count=0;
    for(int i=0;i<32;i++)
    {
        if((n&(1<<i))!=0)
        {
            count++;
        }
    }
    return count;
}
int minCost(int cost[D][D], int n) 
{
    int* dp = new int[1<<n]; 
    int mask=0;
    for(int i=0;i<(1<<n);i++)
    {
        dp[i] = 100000;
    }
    dp[0]=0;
    for(int mask=0 ;mask<(1<<n);mask++)
    {
        int k =countSetBits(mask);
        cout<<k<<endl;
        for(int j=0;j<n;j++)
        {
            if((mask&(1<<j))==0)
            {
                dp[mask|(1<<j)]=min(dp[mask|(1<<j)],dp[mask]+cost[k][j]);
            }
        }
    }
    return dp[(1<<n)-1];
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
    cout<<minCost(cost,n);
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