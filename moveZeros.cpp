#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
void moveZeroes(vector<int>& A) {
        int i=0,j=0;
        int n=A.size();
        while(j<n && i<n)
        {
        
            while(i<n && A[i]!=0)
            {
                i++;
            }
            j=i;
            while(j<n && A[j]==0)
            {
                j++;
            }
            //cout<<i<<" --- "<<j<<endl;
            if(i!=j && i<j & j<n)
            {
              swap(A[i],A[j]);
            }
            else{
                break;
            }
        }
}
void print(vector<int> &A)
{
    for(auto &it : A)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> A(n,0);
        for(auto &it : A)
        {
            cin>>it;
        }
        moveZeroes(A);
        print(A);
    }
    return 0;
}