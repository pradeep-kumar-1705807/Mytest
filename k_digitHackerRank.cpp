#include<bits/stdc++.h>
using namespace std;

#define debugger(x) cout<<x<<" This is a debugger \n";
#define make_pair mp
#define push_back pb
#define defineArray(A,n) int *A =new int[n];

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



void solve(string &str, int K)
{
    int n=str.length();
    int k=K;
    int last=0;
    int index=0;
    vector<char> soln(k,'0'-1);
    for(int index=0;index<k;index++)
    {
        for(int i=last;i<=str.length()-k+index;i++)
        {
            if(str[i]>soln[index])
            {
                soln[index] =  str[i];
                last=i+1;
            }
        }
    }
    //__pV(soln);
    string ans="";
    for(auto &it : soln)
    {
        ans+=it;
    }
    cout<<ans<<endl;
}


int main()
{
    int t;
    string str;
    int k;
    cin>>str>>k;
    solve(str,k);
    return 0;
}





