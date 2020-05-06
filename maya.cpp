#include <bits/stdc++.h> 
using namespace std; 

int binomialCoeff(int n, int k) 
{ 
	int res = 1; 

	if ( k > n - k ) 
		k = n - k; 

	for (int i = 0; i < k; ++i) 
	{ 
		res *= (n - i); 
		res /= (i + 1); 
	} 

	return res; 
} 
 
int main() 
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int> A(n);
    map<int, int > mp;
    for(auto &it : A)
    {
        cin>>it;
        mp[it]++;
    }
    long long res=1;
    for(auto &it: mp)
    {
        if(it.second >1)
        res=res*binomialCoeff(it.second,1);
    }
    cout<<res<<endl;
    }
	return 0; 
} 

