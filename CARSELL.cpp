#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<x<<" This is a debugger \n";
typedef long long int lli;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<long long int> prices(n);
        for( auto &it :prices)
        {
            cin>>it;
        }
        sort(prices.begin(),prices.end(),greater<long long int>());
        for(int i=0;i<prices.size();i++)
        {
            for(int j=i+1;j<prices.size();j++)
            {
                prices[j]--;
                if(prices[j]<0)
                {
                    prices[j]=0;
                }
            }
        }
        long long sum=0;
        for(auto &it : prices)
        {
            sum+=it;
        }
        cout<<(sum)%(lli)(10e9+9)<<endl;
    }
    return 0;
}