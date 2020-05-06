#include<bits/stdc++.h>
using namespace std;

#define debugger(x) cout<<x<<" This is a debugger \n";

const long long  MOD=(long long)(1e9)+7;
const long long  mod=(long long)(1e9)+7;

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




long long summation(long long num)
{
    return  (((num % MOD)*(num+1)%MOD)%MOD)/2;
}
long long  modularExponentiation(long long x,long long n,long long M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}
long long modInverse(long long A,long long M)
{
    return modularExponentiation(A,M-2,M);
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
        long long n;
        cin>>n;
        vector<long long >arr(n),A;
        long long f=0;
        for(auto &it : arr)
        {
            cin>> it;
        }
        for(int i=0;i<arr.size()-1;i++)
        {
            long long temp=(arr[i+1]*modInverse( arr[i],MOD));
            A.push_back(temp);
        }
        for(int i=0;i<A.size();i++)
        {
            A[i]=summation(A[i]);
            f=((f)%MOD+(A[i]%MOD))%MOD;
        }
        long long ans = ((f%MOD) * ((f+1)%MOD)%MOD)/2;
        cout<<ans<<endl;
    }
    return 0;
}





