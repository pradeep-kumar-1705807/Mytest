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
        vector<int> A(n);
        unordered_set<int> us;
        for(auto &it :A)
        {
            cin>>it;
        }
        int count=0;
        long long int pro=1;
        for(int i=0;i<n;i++)
        {
            pro=1;
            for(int j=i;j<n;j++)
            {
                pro*=A[j];
                if(pro%4!=2)
                {
                    count++;
                }
            }
        }
        cout<<count<<endl;
        
    }
    return 0;
}
