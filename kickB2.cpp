#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> & A,int  test)
{
    int n=A.size();
    int checkpoint=0;
    for(int i=1;i<n-1;i++)
    {
        //cout<<A[i]<<"--"<<i<<endl;
        if(A[i]>A[i-1] && A[i] >A[i+1])
        {
            //cout<<A[i]<<endl;
            checkpoint++;
        }
    }
    printf("Case #%d: %d\n",test,checkpoint);
}

int main()
{
    int t;
    cin>>t;
    for( int k=1;k<=t;k++)
    {
        int n,val,target;
        cin>>n;
        vector<int> A(n);
        for(int i=0;i<n;i++)
        {
           cin>>A[i];
            //A.push_back(val);
        }
        solve(A,k);
    }
    return 0;
}