#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long int *A = new long long int[n];
        long long int *dp = new long long int[n];
        for(int i=0;i<n ;i++)
        {
            cin>>A[i];
        }
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(A[i+1]>0 && A[i] < 0)
            {
                dp[i] = dp[i+1]+1;
            }
            else if(A[i+1]<0 && A[i]>0)
            {
                dp[i] = dp[i+1]+1;

            }
            else 
            {
                dp[i]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<dp[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}