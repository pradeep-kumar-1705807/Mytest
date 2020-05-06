#include<bits/stdc++.h>
using namespace std;
void removeIthEntryFromArray(vector<int> &A, int index, int n)
{
    for(int i=index+1;i<n;i++)
    {
        A[i-1]=A[i];
    }
}
int removeDuplicates(vector<int>& A) {
    int ans=0;
    int n=A.size();
    for(int i=1;i<n;i++)
    {
        if(A[i]==A[i-1])
        {
            removeIthEntryFromArray(A,i,n);
            n--;
            i--;
        }
    }
    return n;
}
int main()
{
    int n;
    cin>>n;
    vector<int> vp(n);
    for(auto &it : vp)
    {
        cin>>it;
    }
    cout<<removeDuplicates(vp)<<endl;
    for(auto &it : vp)
    {
        cout<<it<<" ";
    }
    return 0;
}