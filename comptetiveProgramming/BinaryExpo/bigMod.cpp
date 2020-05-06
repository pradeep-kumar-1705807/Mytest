#include<bits/stdc++.h>
using namespace std;
long long pow(long long a, long long b ,long long M)
{
    if(b==1)
    {
        return a;
    }
    long long res = pow(a,b/2,M);
    if(b%2==0)
    {
        return (res%M)*(res%M)%M;
    }
    else
    {
        return (a%M)*(res%M)*(res%M)%M;
    }
    
}
int main()
{
    long long a,b,M;
    while(cin>>a>>b>>M)
    {
        cout<<pow(a,b,M)<<endl;
    }
    return 0;
}