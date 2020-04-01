#include<bits/stdc++.h>
using namespace std;
int lowerBinarySearch(int *A, int l , int u, int target) 
{
    if(l==u) 
    {
        if(A[l]==target) 
        {
            return l;
        }
        else {
            return -1;
        }
    }
    int mid=(l+u)/2;
    if(target < A[mid])
    {
        return lowerBinarySearch(A,l,mid,target);
    }
    else if(target > A[mid])
    {
        return lowerBinarySearch(A,mid+1, u, target);
    }
    else if(A[mid]==target)
    {
        if(mid==0)
        {
            return 0;
        }
        else if(A[mid-1] != target)
        {
            return mid;
        }
        else if(A[mid-1] == target)
        {
            return lowerBinarySearch(A,l,mid-1,target);
        }
    }
    return -1;    
}
int upperBinarySearch(int *A , int l, int u,int n, int target)
{
    if(l==u)
    {
        if(A[l]==target)
        {
            return l;
        }
        return -1;
    }
    int mid=(l+u)/2;

    if(target < A[mid] )
    {
        return upperBinarySearch(A,l,mid,n,target);
    }
    else if(target > A[mid])
    {
        return upperBinarySearch(A,mid+1,u,n,target);
    }
    else if(target == A[mid])
    {
        if(mid==n-1)
        {
            return n-1;
        }
        else if(A[mid+1] != target)
        {
            return mid;
        }
        else if( A[mid+1] == target)
        {
            return upperBinarySearch(A,mid+1,u,n,target);
        }
    }
    return -1;
}
int main()
{
    /*int t;
    cin>>t;
    while(t--)
    {*/
        int n, target;
        cin>>n;
        int *A =new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
        }
        cin>> target;
        int lower=lowerBinarySearch(A,0,n-1,target);
        int upper=upperBinarySearch(A,0,n-1,n,target);
        if(lower!=-1) {
            cout<<upper-lower+1<<endl;
        }
        else 
        {
            cout<<-1<<endl;
        }

    //}
    return 0;
}