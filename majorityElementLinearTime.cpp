#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums)
{
    int n=nums.size();
    int lastIndex=n-(n/2+1);
    int s=n/2;
   // cout<<"last Index : "<<lastIndex<<" size : "<<s<<endl;
    int ans=-1;
    for(int i=0;i<=lastIndex;i++)
    {
     //   cout<<nums[i]<<" -- "<<nums[i+s]<<endl;
        if(nums[i]==nums[i+s])
        {
            ans=nums[i];
            break;
        }
    }
    return ans;
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
        for(auto &it : A)
        {
            cin>>it;
        }
        cout<<majorityElement(A)<<endl;
    }
    return 0;
}