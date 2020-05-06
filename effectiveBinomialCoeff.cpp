#include<bits/stdc++.h>
using namespace std;
long long getBino(long long n , long long k)
{
    int res=1;
    for(int i=0;i<k;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<getBino(n,k);
    return 0;
}