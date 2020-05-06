#include<bits/stdc++.h>
using namespace std;
int numberOfSubarrays(vector<int>& A, int k) {
    int count=0, ans=0;
    int n=A.size();
    int f=0;
    for(int i=0;i<n;i++)
    {
            f=0;
            count=0;
            for(int j=i;j<n;j++)
            {
                if(A[j]%2!=0)
                {
                    count++;
                }
                if(count==k){
                    ans++;
                }
              
            }

    }
    return ans;   
}
int main()
{
    int n;
    cin>>n;
    vector<int> A;
    for(auto &it : A)
    {
        cin>>it;
    }
    return 0;
}