#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &A, int l  ,int u)
{
    if(l==u)
    {
        return A[l];
    }
    int mid=(l+u)/2;
    if(A[l]>A[mid])
    {
        return binarySearch(A,l,mid);
    }
    else if(A[u]<A[mid])
    {
        return binarySearch(A,mid+1,u);
    }
    else 
    {
        if(mid>0 && mid< A.size()-1)
        {
            if(A[mid-1]<A[mid] && A[mid+1]>A[mid] )
            {
                 return binarySearch(A,l,mid);
            }
            else if( A[mid-1]>A[mid] && A[mid+1] >A[mid])
            {
                return A[mid];
            }
            
        } 
        else if(mid ==0 ||mid ==A.size()-1)
        {
            return A[mid];
        }

    }
    return -1;

}
int findMin(vector<int>& nums) {
    int  l=0;
    int  u=nums.size()-1;
    return binarySearch(nums,l,u);
}
int main()
{
    int n;
    cin>>n;
    vector<int > A(n);
    for(auto &it : A)
    {
        cin>>it;
    }
    cout<<findMin(A)<<endl;
    return 0;
}