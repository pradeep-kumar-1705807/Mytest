#include<bits/stdc++.h>
using namespace std;
 int countElements(vector<int>& arr) {
        map<int , int > mp;
        int
        for(auto &it : mp)
        {
            mp[it]++;
        }
        for(int i=0;i<arr.size();i++)
        {
            if(mp[A[i]+1]>0)
            {
                count++;
                mp[A[i]+1]--;
            }
        }
        return count;
        
}
int main()
{
    int n;
    cin>>n;
    for(auto &it :A )
    {
        cin>>it;
    }
    cout<<countElements(A);
    return 0;
}