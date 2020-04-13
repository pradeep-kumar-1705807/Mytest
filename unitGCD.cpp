#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> soln;
        if(n%2==0)
        {
            cout<<(n/2)<<endl;
            for(int i=1;i<n;i+=2)
            {
                cout<<2<<" "<<i<<" "<<i+1<<endl;
            }
        }
        else{
            cout<<n/2<<endl;
            cout<<3<<" "<<1<<" "<<2<<" "<<3<<endl;
            for(int i=4;i<n;i+=2)
            {
                cout<<2<<" "<<i<<" "<<i+1<<endl;
            }        
        }
    }
}