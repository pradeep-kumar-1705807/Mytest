#include <bits/stdc++.h>
using namespace std;
int getMexVal(vector<int> &A, int l, int u)
{
    int min_val=1000000;
    int max_val=-1;
    vector<int> soln;
    for(int i=l;i<=u;i++)
    {
        soln.push_back(A[i]);
        if(min_val>A[i])
        {
            min_val=A[i];
        }
    }
    if(min_val!=1)
    {
        return 1;
    }
    else
    {
        sort(soln.begin(),soln.end());
        for(int i=0;i<soln.size()-1;i++)
        {
            if(soln[i]+1!=soln[i+1])
            {
                return soln[i]+1;
            }
        }
        return soln[soln.size()-1]+1;
    }
    return -1;
}


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        std::vector<int> A(n);
        for(auto &it : A)
        {
            cin>>it;
        }
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=getMexVal(A,i,j);
            }
        }
        cout<<sum<<endl;
    }
	return 0;
}
