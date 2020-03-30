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
        vector<int> arr(n+1);
        for( int i=1;i<n+1;i++)
        {
            cin>>arr[i];
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=i+1;j<n+1;j++)
            {
                if(j%i==0)
                {
                    arr[j]-=arr[i];
                }
            }
        }
        for(int i=1;i<n+1;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}