#include<bits/stdc++.h>
using namespace std;
bool checkPrime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			return false;
		}

	}
	return true;
}
int main()
{
	//cout<<(46349*46337)<<endl;
	//freopen("out2","w",stdout);
	int i=0;
	long long k=1;
	long long x=(k<<32)-1;
	//cout<<(46327*46337)<<endl;
	//cout<<x<<endl;
	int count=0;
	for(int i=2;i<=sqrt(x);i++)
	{
		if(checkPrime(i))
		{
			cout<<i<<"\n";
			count++;
		}
	}
	cout<<"\n------------------------------\n";
	cout<<count<<endl;
}
