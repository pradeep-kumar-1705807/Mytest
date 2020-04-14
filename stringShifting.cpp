#include<bits/stdc++.h>
using namespace std;
string shiftRight(string &s, int k)
{
    int n=s.length();
    k=k%n;
    string ans="";
    for(int i=n-k;i<n;i++)
    {
        ans+=s[i];
    }
    for(int i=0;i<k;i++)
    {
        ans+=s[i];
    }
    return ans;
}
string shiftLeft(string &s, int k)
{
    int n=s.length();
    k=k%n;
    string ans="";
    for(int i=k;i<n;i++)
    {
        ans+=s[i];
    }
    for(int i=0;i<k;i++)
    {
        ans+=s[i];
    }
    return ans;
}
string stringShift(string s, vector<vector<int>>& shift) {
    int n=shift.size();
    int dir=0;
    for(int i=0;i<n;i++)
    {
          if(shift[i][0]==0)
          {
              dir-=shift[i][1];
          } 
          else{
              dir+=shift[i][1];
          }
    }
    string ans="";
    if(dir==0)
    {
        ans=s;
    }
    else if( dir < 0)
    {
        ans= shiftLeft(s,dir);
    }
    else if(dir> 0)
    {
        ans=shiftRight(s,dir);
    }
    return ans;
}
int main()
{
    
    return 0;
}