#include<bits/stdc++.h>
using namespace std;
#define debugger(x) cout<<x<<" This is a debugger \n";
#define  mp make_pair
#define lli long long int
#define  pb push_back
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
    
}





int binarySearch(int *A, int l, int u)
{
    if(l==u)
    {
        if(A[l]-1 == l)
        {
            return l+1;
        }
        return -1;
    }
    int mid=(l+u)/2;
    if(A[mid]-1>mid)
    {
        return binarySearch(A,l,mid);
    }
    else if(A[mid]-1<mid)
    {
        return binarySearch(A,l,mid);
    }
    else if(A[mid]-1== mid)
    {
        return mid+1;
    }
    return -1;
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
        int n;
        cin>>n;
        vector<int> vp;
        int *A =new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            if(A[i]==i+1)
            {
                vp.push_back(i+1);
            }
        }
        __pV(vp);
    }
    return 0;
}





