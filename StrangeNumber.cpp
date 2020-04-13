#include<bits/stdc++.h>
using namespace std;
int countFactor(long long int n)
{
    unordered_map<int , int> mp;
    for(int i=2;i<=ceil(sqrt(n));i++)
    {
        if(n%i==0)
        {
          //  cout<<i<<" --";
            mp[i]=0;
        }
    }
    int count=0;
    for(auto &it :mp)
    {
        int val=it.first;
        int temp=n;
        int freq=0;
        while(temp%val==0)
        {
            freq++;
            temp=temp/val;
        }
        it.second=freq;
        count+=freq;
    }
    for( auto &it : mp)
    {
       // cout<<it.first<<" ## "<<it.second<<endl;
    }
    return count;
}
bool checkDivisibleByTwo(long long int n)
{
    long long int  k=1;
    k=k<<32;
    if(k%n == 0)
    {
        return true;
    }
    return false;
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