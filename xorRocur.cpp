#include<bits/stdc++.h>
using namespace std;
int returnDuplicate(vector<int> &A, int index)
{
    if(index==A.size())
    {
        return 0;
    }
    int ans=0;
    ans^=A[index]^returnDuplicate(A, index+1);
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
        cout<<returnDuplicate(A,0);
    }
    return 0;
}