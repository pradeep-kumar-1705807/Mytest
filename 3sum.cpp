#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &A)
{
    int n=A.size(); 
    int i,j,k;
    unordered_map<int, int> ump;
    set<vector<int>> tempSoln;
    vector<vector<int>> soln;
    if(A.size()<3)
    {
        return soln;
    }
    for(auto &it : A)
    {
        ump[it]++;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                ump[A[i]]--;
                ump[A[j]]--;
                int third=-(A[i]+A[j]);
                if(ump.find(third)!=ump.end() && ump[third]>0 )
                {
                    int a=A[i],b=A[j],c=-(A[i]+A[j]);
                   // cout<<a<<" -- "<<b<<" -- "<<c<<endl;
                    vector<int> ans={a,b,c};
                    sort(ans.begin(),ans.end());
                    tempSoln.insert(ans);
                }
                ump[A[i]]++;
                ump[A[j]]++;
            }
        }
    }
    for(auto &it : tempSoln)
    {
        soln.push_back(it);
        for(auto &jt: it)
        {
            cout<<jt<<" ";
        }
        cout<<endl;
    }

    return soln;
}
int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(auto &it : A)
    {
        cin>>it;
    }  
   vector<vector<int>> soln=threeSum(A);
    return 0;
}