#include<bits/stdc++.h>
using namespace std;

#define debugger(x) cout<<x<<" This is a debugger \n";
#define make_pair mp
#define lli long long int
#define push_back pb


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

bool check(vector<vector<int>> &grid, int x, int y)
{
    int n=grid.size();
    int m=grid[0].size();
    
    if(x-1>=0 && grid[x][y]==1)
    {
        
    }
}

int orangesRotting(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    int count=0;
    for(int i=0; i< n ;i++)
    {
        for(int j=0; j<m ;j++)
        {
            if(grid[i][j]==2 &&check(grid,i,j)==true)
            {
                count++;
            }
        }
    }    
    return count;
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
        int n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>val;
                grid.push_back(val);
            }
        }
        
    }
    cout<<orangesRotting(grid)<<endl;
    return 0;
}





