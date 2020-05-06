#include<bits/stdc++.h>
using namespace std;
void solve(vector<long long> & A,long long days ,int  test)
{
    int n=A.size();
    long long ans=0;
    long long one=0;
    sort(A.begin(),A.end(),greater<int>());
    
    for(int i=0;i<n;i++)
    {
        if(__gcd(days,A[i])==1)
        {
            long long t;
            one=max(one,A[i]);
            t=days/one;
            ans=t*one;
        }
    }
    if(ans==INT_MAX)
    {
        long long temp=*max_element(A.begin(),A.end());
        long long t=days/temp;
        ans=t*temp;
    }
    printf("Case #%d: %lld\n",test,ans);
}

int main()
{
    int t;
    cin>>t;
    for( int k=1;k<=t;k++)
    {
      long long n,val,target,D;
        cin>>n>>D;
        vector<long long> A(n);
        for(int i=0;i<n;i++)
        {
           cin>>A[i];
            //A.push_back(val);
        }
        solve(A,D,k);
    }
    return 0;
}