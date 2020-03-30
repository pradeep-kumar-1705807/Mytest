#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxCostKnapsack(int W, vector<int> &weight , vector<int> &price ,int index, int **dp)
{
    if(W==0 || index ==weight.size())
    {
        return 0;
    }
    if(weight[index]>W)
    {
        return maxCostKnapsack(W,weight,price,index+1,dp);
    }
    if(dp[index][W]>-1)
    {
        return dp[index][W];if(dp[index][W]>-1)
    {
        return dp[index][W];
    }
    }
    int ans1=price[index]+maxCostKnapsack(W-weight[index],weight,price,index+1,dp);
    int ans2=maxCostKnapsack(W,weight,price,index+1,dp);
    dp[index][W]=max(ans1,ans2);
    return dp[index][W];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,w;
        cin>>n>>w;
        vector<int> weight(n);
        vector<int> price(n);
        for(auto &it :price)
        {
            cin>>it;
        }
        for(auto &it : weight)
        {
            cin>>it;
        }
        int **dp = new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i] =  new int[w+1];
            for(int j=0;j<=w;j++)
            {
                dp[i][j]=-1;
            }
        }
        cout<<maxCostKnapsack(w,weight,price,0,dp)<<endl;
        
    }
    return 0;
}