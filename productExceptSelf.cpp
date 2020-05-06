#include<bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n),right(n),soln(n,1);
    left[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        left[i]=left[i-1]*nums[i];
    }
    right[n-1]=nums[n-1];
    for(int j=nums.size()-2;j>=0;j--)
    {
        right[j]=right[j+1]*nums[j];
    }
    soln[0]=right[1];
    soln[soln.size()-1]=left[left.size()-2];
    for(int i=1;i<nums.size()-1;i++)
    {
        soln[i]=left[i-1]*right[i+1];
    }
    return soln;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> A(n);
        for(auto &it :A)
        {
            cin>>it;
        }
        for( auto &it :productExceptSelf(A))
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}