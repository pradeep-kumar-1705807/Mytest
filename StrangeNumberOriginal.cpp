#include<bits/stdc++.h>
using namespace std;
int countFactor(long long int n)
{
    int count=1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long long int k,x;
        cin>>x>>k;
        int ans=countFactor(x);
        cout<<x<<" "<<ans<<" ";
        if(ans>=k)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
        
    }
}