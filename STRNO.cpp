#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int n)
{
    for(int i=2;i<=sqrt(n);i++) {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int countFactor(int n)
{
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            count++;
        }
    }
    return count;
}
int countPrimeFactor(int n)
{
    int primeCount=0;
    for(int i=2;i<=n;i++)
    {
        if(n%i==0 && checkPrime(i)==true)
        {
            primeCount++;
        }
    }
    return primeCount;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x ,k;
        cin>>x>>k;
        int factor=0,primeFactor=0;
        int i=2;
        bool flag=true;
        while(flag)
        {
            factor=countFactor(i);
            primeFactor=countPrimeFactor(i);
            cout<<factor<<" ------ "<<primeFactor<<" ----  "<<i<<endl;
            if(factor == x && primeFactor == k)
            {
                flag=false;
                break;
            }
            i++;
        }
        cout<<i<<endl;
        cout<<factor<<"=f -- p= "<<primeFactor<<endl;
        if(factor == x && primeFactor == k)
        {
            cout<<"1\n";
        }
        else 
        {
            cout<<"0\n";
        } 
    }
    return 0;
}