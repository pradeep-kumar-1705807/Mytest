#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}

void removeElement(vector<int>& A,int  val) {
        int i=0,j=0;
        int n=A.size();
        while(j<n && i<n)
        {
        
            while(i<n && A[i]!=val)
            {
                i++;
            }
            j=i;
            while(j<n && A[j]==val)
            {
                j++;
            }
           // cout<<i<<" --- "<<j<<endl;
            if(i!=j && i<j & j<n)
            {
              swap(A[i],A[j]);
            }
            else{
                break;
            }
        }
        for(auto it=A.begin();it!=A.end();it++)
        {
            if(*it==val)
            {
                A.erase(it,A.end());
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
        int n,val;
        cin>>n>>val;
        vector<int> A(n,0);
        for(auto &it : A)
        {
            cin>>it;
        }
        removeElement1(A,val);
        print(A);
    }
    return 0;
}