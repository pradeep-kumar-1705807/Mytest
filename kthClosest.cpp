#include<bits/stdc++.h>
using namespace std;
int upperBoundBinarySearch(vector<int> &A, int target, int l , int u){
    if(l==u)
    {
        if(A[l]==target)
        {
            return l;
        }
        else{
            if(l==0)
            {
                return 0;
            }
            else if( l==A.size()-1)
            {
                return A.size()-1;
            }
            else{
                return l+1;
            }
        }
    }
    int mid = (l+u)/2;
    if(target < A[mid])
    {
        return upperBoundBinarySearch(A,target,l,mid);
    }
    else if(target > A[mid])
    {
        return upperBoundBinarySearch(A,target,mid+1,u);
    }
    else if(target == A[mid])
    {
        return mid;
    }
}
vector<int> findClosestElements(vector<int>& A, int k, int x) 
{
    vector<int> soln;
    int n=A.size()-1;
    int index =  upperBoundBinarySearch(A, x, 0, n-1);
    cout<<"Index :) "<<index<<endl;
    if(index == 0)
    {
        for(int i=0;i<k;i++)
        {
            soln.push_back(A[i]);
        }

    }
    else if( index == n-1)
    {
        for(int i=n-1;i>=n-k;i--)
        {
            soln.push_back(A[i]);
        }
    }
    else 
    {
        int count=k-1;
        int i=index-1;
        int j=index+1;
        soln.push_back(A[index]);
        while(count>0)
        {
            if(i>-1 && abs(x-A[i])<=abs(x-A[j]))
            {
                soln.push_back(A[i]);
                i--;
            }
            else if(j<A.size() && abs(x-A[i])>abs(x-A[j]))
            {
                soln.push_back(A[j]);
                j++;
            }
            count--;
        }
        while(count>0 && j>=A.size()&& i>-1)
        {
            soln.push_back(A[i]);
            i--;
            count--;
        }
        while(count >0 && i<=0 &&j<A.size())
        {
            soln.push_back(A[j]);
            j++;
            count--;
        }
    }
    sort(soln.begin(),soln.end());
    return soln;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int k,x;
    vector<int> vp(n);
    for(auto &it :vp)
    {
        cin>>it;
    }
    cin>>k>>x;
   vector<int> ans= findClosestElements(vp,k,x);
   for(auto &it : ans)
   {
       cout<<it<<" ";
   }
    }
    return 0;
}