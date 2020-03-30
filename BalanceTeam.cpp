#include<bits/stdc++.h>
using namespace std;
int maxBalanceTeamSize(int *A , int n)
{
    sort(A,A+n);
    int maxStrength=0;
    for(int i=0;i<n;i++)
    {
       int  len=0;
        for( int j=i;j<n;j++)
        {
            if(A[j]-A[i]<=5)
            {
                len++;
            }
        }
        if(len>maxStrength)
        {
            maxStrength=len;
        }
    }
    return maxStrength;
}
int main()
{
    int n;
    cin>>n;
    int *A = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<maxBalanceTeamSize(A,n)<<endl;
    return 0;
}