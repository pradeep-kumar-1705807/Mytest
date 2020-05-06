#include<bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) 
{
    int ans=0;
    if(dividend == INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }
    if(divisor == -1)
    {
        return -(dividend);
    }
    if(divisor == 1)
    {
        return dividend;
    }
    int sum=dividend;
    int count=0;
    if(dividend>0)
    {
        while(sum>0)
        {
            sum-=divisor;
            count++;
        }
            
    }
    else if(dividend<0)
    {
        while(sum<0)
        {
            sum-=divisor;
            count++;
        }
            
    }
        return count;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        cout<<divide(n,d);
    }
    return 0;
}