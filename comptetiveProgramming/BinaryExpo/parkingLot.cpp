#include<bits/stdc++.h>
using namespace std;
long long solve(long long n)
{
    if(n==3)
    {
        return 2*3*4*pow(4,n-3);
    }
    return 2*(3*4*pow(4,n-3));
}
int main()
{
    long long n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}