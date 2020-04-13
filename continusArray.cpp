#include<bits/stdc++.h>
using namespace std;
int findMaxLength(vector<int>& nums) {
    int n=nums.size();
    int ans=0;
    unordered_map<int , vector<int>> ump;
    ump[0].push_back(0);
    vector<int> leftSum(n);
    if(nums[0]==0)
    {
        leftSum[0]=1;
    }
    else{
        leftSum[0]=-1;
    }
    for(int  i=1;i<n;i++)
    {
        if(nums[i]==0)
        {
            leftSum[i]=leftSum[i-1]+1;
        }
        else{
            leftSum[i]=leftSum[i-1]-1;
        }
    }
    for(int i=0;i<n;i++)
    {
        ump[leftSum[i]].push_back(i+1);
    }
    for(auto &it :ump)
    {
        if(it.second.size()>1)
        {
            int temp=it.second.size();
            ans=max(ans,it.second[temp-1]-it.second[0]);
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int> A(n);
    for(auto &it :A)
    {
        cin>>it;
    }
    cout<<findMaxLength(A)<<endl;
    }
    return 0;
}