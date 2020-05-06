#include<bits/stdc++.h>
using namespace std;
long long moduloPower(long long x,long long y , long long n)
{
    if(y==1)
    {
        return x;
    }
    long long res=moduloPower(x,y/2,n);
    if(y%2==0)
    {
        return ((res%n) *(res %n))%n;
    }
    else 
    {
        return ((x%n)* (res%n)*(res%n))%n;
    }
}
int main()
{
    int c;
    cin>>c;
    while(c--)
    {
    long long x,y,n,z;
    cin>>x>>y>>n;
    z=moduloPower(x,y,n);
    cout<<z<<endl;    
    }
    int zero;
    cin>>zero;
    return 0;
}