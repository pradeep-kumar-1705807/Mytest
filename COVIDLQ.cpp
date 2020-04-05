#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<x<<" This is a debugger \n";


bool solve(vector<int> A)
{
    if(A.size()==0)
    {
        return true;
    }
    for(int i=0;i<A.size()-1;i++)
    {
        if(A[i+1]-A[i]<6)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> A(n);
        vector<int> index;
        for( int i=0;i<A.size();i++)
        {
            cin>>A[i];
            if(A[i]==1)
            {
                
                index.push_back(i);
            }
        }
        bool ans=solve(index);
        if(ans==true)
        {
            printf("YES\n");
        }
        else 
        {
            printf("NO\n");
        }
    }
    return 0;
}