#include<bits/stdc++.h>
#define deb(x) cout<<x<<" Debugger \n";
using namespace std;

//Time = O( log(n) )
//Space = O(1)

int binarySearch( vector<int> &A , int l , int  u ,int d)
{
    if(l == u)
    {
        return A[l];
    }
    int mid= (l+u)/2;
    int midValue =  A[0]+mid*d;
    if(A[mid]!=midValue)
    {
        return binarySearch(A,l,mid,d);
    }
    else 
    {
        return binarySearch(A, mid+1, u, d);
    }

}

int  missingNumberInAp(vector<int> A) {
    int n=A.size();
    int d=(A[A.size()-1]-A[0])/n;
    int ans = binarySearch(A, 0 , A.size()-1,d);
    return ans-d;
}

//Time = O(n);
//Space = O(1);

int bruteForceSoln( vector<int> &A) 
{
    if(A.size()==0)
    {
        return -1;
    }
    int n=A.size();
    int ans=-1;
    int d=(A[A.size()-1]-A[0])/n;
    for(int i=0;i<n;i++)
    {
        if(A[i]+d!=A[i+1])
        {
            ans=A[i]+d;
            break;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(auto &it :A ) 
    {
        scanf("%d",&it);
    }
    cout<<"Brute Force :) "<<bruteForceSoln(A)<<endl;
    cout<<"Binary Search:)"<<missingNumberInAp(A)<<endl;
    return 0;
}