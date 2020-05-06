#include<bits/stdc++.h>
using namespace std;

vector<int> seive(int A,unordered_set<int > &us)
{
    vector<int > soln;
    vector<char> Hash(A,'1');
    Hash[0]='0';
    Hash[1]='0';
    for(int i=2;i<A;i++)
    {
        for(int j=2;i*j<Hash.size();j++)
        {
            Hash[j*i]='0';
        }
    }
    for(int i=0;i<Hash.size();i++)
    {
        if(Hash[i]=='1'){
            us.insert(i);
        soln.push_back(i);
        }
    }
    return soln;
}
vector<int> primesum(int A) {
    unordered_set<int> us;
    vector<int> soln(2);
    vector<int> primes = seive(A,us);
    for(auto &it : primes)
    {
        if(us.find(A-it)!=us.end())
        {
            soln[0]=it;
            soln[1]=A-it;
            break;
        }
    }
    return soln;
}


int main()
{
    int A;
    cin>>A;
    vector<int> ans=primesum(A);
    cout<<ans[0]<<" "<<ans[1]<<endl; 
    return 0;
}