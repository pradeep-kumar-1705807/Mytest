#include<bits/stdc++.h>
using namespace std;

#define debugger(x) cout<<x<<" This is a debugger \n";
#define make_pair mp
#define push_back pb

typedef long long int lli;

template< typename  T > void __pV(vector<T> &vp)   {  for(auto &it : vp) { cout<<it<<" "; } cout<<endl; }
template< typename  T > void __pM(map<T, T> &mp)    {  for(auto &it :mp) { cout<<it.first<<" "<<it.second<<endl; } cout<<endl; }
template< typename  T1,typename T2 > void __pM(map<T1, T2> &mp) {  for(auto &it :mp) { cout<<it.first<<" "<<it.second<<endl; } cout<<endl; }
template< typename  T > void __pM(multimap<T, T > &mp)    {  for(auto &it :mp) { cout<<it.first<<" "<<it.second<<endl; } cout<<endl; }
template< typename  T1,typename T2 > void __pM(multimap<T1, T2> &mp) {  for(auto &it :mp) { cout<<it.first<<" "<<it.second<<endl; } cout<<endl; }
template< typename  T > void __pM(unordered_map <T, T> &mp)    {  for(auto &it :mp) { cout<<it.first<<" "<<it.second<<endl; } cout<<endl; }
template< typename  T1,typename T2> void __pM(unordered_map<T1, T2> &mp) {  for(auto &it :mp) { cout<<it.first<<" "<<it.second<<endl; } cout<<endl; }
template< typename  T > void __pM(unordered_multimap<T, T> &mp)    {  for(auto &it :mp) { cout<<it.first<<" "<<it.second<<endl; } cout<<endl; }
template< typename  T1,typename T2> void __pM(unordered_multimap <T1, T2> &mp) {  for(auto &it :mp) { cout<<it.first<<" "<<it.second<<endl; } cout<<endl; }
template< typename  T > void __pS(set<T> &s)    {  for(auto &it :s) { cout<<it<<" "; } cout<<endl; }
template< typename  T > void __pS(multiset<T> &s)    {  for(auto &it :s) { cout<<it<<" "; } cout<<endl; }
template< typename  T > void __pS(unordered_set<T> &s)    {  for(auto &it :s) { cout<<it<<" "; } cout<<endl; }
template< typename  T > void __pS(unordered_multiset<T> &s)    {  for(auto &it :s) { cout<<it<<" "; } cout<<endl; }
template< typename  T > void __pA(T *Arr , int n) { for( int i=0;i<n;i++) { cout<<Arr[i]<<" "; }  cout<<endl; }

string rotate(string &s1)
{
    int n=s1.length();
    string ans="";
    for(int i=1;i<n;i++)
    {
        ans+=s1[i];
    }
    ans+=s1[0];
    return ans;
}
bool solution1(string str1,string str2)
{
    set<string> s;
    int n=str1.length();
    string ans=str1;
    for(int i=0;i<n;i++)
    {
       ans = rotate(ans);
       s.insert(ans);
    }  
    if(s.find(str2)==s.end())
    {
        return false;
    }
    return true;
}
bool soluation2(string s1, string s2)
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout<<solution1(str1,str2)<<endl;
    }
    return 0;
}





