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
    while(t--)
    {
    int n;
    cin>>n;
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2!=0)
        {
            count++;
        }
    }
    long long res=binomialCoeff(count,2);
    cout<<res<<endl;
  }

	return 0; 
} 

