#include<bits/stdc++.h>
using namespace std;
long long noOfWays(long long **like, int n, int pth ,int mask)
{
    if(mask==((1<<n)-1))
    {
        return 1;
    }
    if(pth>=n)
    {
        return 0;
    }
    long long ans=0;
    for(int j=0;j<=n;j++)
    {
        if(like[pth][j]==1 && (mask & (1<<j))==0)
        {
            ans+=noOfWays(like,n , pth+1,mask|(1<<j));
        }
    }
    return ans;

}

long long solve(long long **like, int n)
{
    long long mask=0;
    return noOfWays(like, n,0,0);
}
int main()
{
    int n;
    cin>>n;
    long long **like=new long long*[n];
    for(int i=0;i<n;i++)
    {
        like[i]=new long long[n];
        for(int j=0;j<n;j++)
        {
            cin>>like[i][j];
        }
    }
    cout<<solve(like,n)<<endl;
    return 0;

}