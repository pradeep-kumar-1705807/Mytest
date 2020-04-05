#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int i=0,b;
      char ch;
      cin>>b;
      string soln="";
      while(b--)
      {
        cout<<i+1<<endl;
        fflush(stdout);
        cin>>ch;
        
        soln+=ch;
        i++;
      }   
      string s;
      cin>>s;
      cout<<soln<<endl;
  }
  return 0;
}