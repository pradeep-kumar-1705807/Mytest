#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &A, int l  ,int u)
{
    if(l==u)
    {
        return l;
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
                return mid ;
            }
            
        } 
        else if(mid ==0 ||mid ==A.size()-1)
        {
            return mid;
        }

    }
    return -1;

}
int findMinIndex(vector<int>& nums) {
    int  l=0;
    int  u=nums.size()-1;
    return binarySearch(nums,l,u);
}
bool isPresent(vector<int> &A, int l, int u, int target)
{
    if(l==u)
    {
        if(A[l]==target)
        {
            return true;
        }
        return false;
    }
    int mid=(l + u) /2;
    if(target < A[mid])
    {
        return isPresent(A,l,mid,target);
    }
    else if(target > A[mid])
    {
        return isPresent(A,mid+1,u,target);
    }
    else if(target==A[mid])
    {
        return true;
    }
    return false;
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> A(n);
    for(auto &it : A)
    {
        cin>>it;
    }
    int minIndex=findMinIndex(A);
    cout<<minIndex;
    int l=0,m=minIndex,u=n-1;
    int ans1=isPresent(A,l,minIndex,target);
    int ans2=isPresent(A,minIndex,u,target);
    if(ans1||ans2)
    {
        cout<<"True \n";
    }
    else {
        cout<<"False \n";
    }

    return 0;
}