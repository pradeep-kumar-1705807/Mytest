#include<bits/stdc++.h>
using namespace std;
int longestSubsequence1(vector<int>& A, int diff)
{
    int n=A.size();
    vector<int> dp(n);
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(A[i]-A[j]==diff)
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int maxLen=0;
    for(int i=0;i<dp.size();i++)
    {
        if(maxLen<dp[i])
        {
            maxLen=dp[i];
        }
    }
    return maxLen;
}

int longestSubsequence(vector<int>& A, int diff)
{
    int n=A.size();
    vector<int> dp(n);
    map<int , int> ump;
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        if(ump.find(A[i]-diff)!=ump.end())
        {
            ump[A[i]]=ump[A[i]-diff]+1;
        }
        else 
        {
            ump[A[i]]=1;
        }
    }
    int maxLen=0;
    for(auto &it : ump)
    {
        if(maxLen<it.second)
        {
            maxLen=it.second;
        }
    }
    return maxLen;
}

int main()
{
    int n,diff;
    cin>>n>>diff;
    vector<int> A(n);
    for(auto &it : A)
    {
        cin>>it;
    }
    cout<<longestSubsequence(A,diff)<<endl;
    return 0;
}
/*
9 -2
1 5 7 8 5 3 4 2 1
*/