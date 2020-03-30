#include<bits/stdc++.h>
using namespace std;
int minSteps(string s, string t) {
    int Hash[26]={0};
    int count=0;
    for(auto &it : s)
    {
        Hash[it-'a']++;
    }
    for(auto &it : t)
    {
        if(Hash[it-'a']!=0)
        {
            Hash[it-'a']--;
        }
    }    
    int sum=0;
    for(int i=0;i<26;i++)
    {
        sum+=Hash[i];
    }
    return sum;

}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<minSteps(s,t)<<endl;
    return 0;
}