#include<bits/stdc++.h>
using namespace std;
bool isPossibleToShip(vector<int> &A , int capacity, int days)
{
    int i=0;
    int sumWeight=0;
    int d=1;
    for(i=0;i<A.size() ;i++)
    {
        sumWeight += A[i];
        if(sumWeight > capacity)
        {
            sumWeight = A[i];
            d++;
        }
    }
    if(sumWeight > capacity)
    {
        d++;
    }
    if(d<=days)
    {
        return true;
    }

    return false;
}
int binarySearch(vector<int> &A, int days,int l , int u)
{
    if(l==u)
    {
        if(isPossibleToShip(A,l,days)==true)
        {
            return l;
        }
        return -1;
    }
    int mid= (l+u)/2;
    if(isPossibleToShip(A,mid,days)==true)
    {
        return binarySearch(A,days,l,mid);
    }
    else 
    {
        return binarySearch(A,days,mid+1,u);
    }
}
int shipWithinDays(vector<int>& weights, int D) 
{
    int lower=*max_element(weights.begin(),weights.end());
    int upper=0;
    for(auto &it : weights)
    {
        upper+=it;
    }
    int ans=INT_MAX;
    ans=binarySearch(weights,D,lower,upper);
    return ans;
}
int main()
{

    int n,D;
    cin>>n>>D;
    vector<int> A(n);
    for(auto &it :A)
    {
        cin>>it;
    }
     cout<<shipWithinDays(A,D)<<endl;
    return 0;
}