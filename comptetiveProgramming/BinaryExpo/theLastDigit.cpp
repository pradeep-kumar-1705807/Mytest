#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{long long a, b;
map<long, long > mp;
cin>>a>>b;
if(a==0||b==0||a==1||b==1)
{if(a==0) cout<<0<<endl;else if(b==0) cout<<b<<endl;else if(b==1) cout<<a%10<<endl;else if(a==1) cout<<1<<endl;
    }
    else{
int i=1;
long long res=a;
while(mp.find(res)==mp.end())
{
mp[res]=i;res=(res*a)%10;i++;
}long long power1 = i-1;long long power2 = b%power1;long long last1=1,last2=1;
    for(auto &it : mp)
    {if(it.second==power1){
        last1=it.first;
        }
    if(it.second==power2)
    {
    last2=it.first;
    }
}int result = (last1 *last2)%10;
cout<<result<<endl;}}return 0;
}