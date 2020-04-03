#include<bits/stdc++.h>

#define deb(x) cout<<x<<" Debugger \n";
void swap(int &a , int &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
using namespace std;
int main()
{
    int n;
    vector<int> A(n);
    for(auto &&it :A ) 
    {
        scanf("%d",&it);
    }
    return 0;
}