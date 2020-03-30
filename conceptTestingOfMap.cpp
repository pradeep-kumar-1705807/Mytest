#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int,string> ump;
    map<int,string> mp;
    unordered_map<int,int> ump1;
    map<int,int> mp1;
    ump[1]="Pradeep Kumar";
    mp[2]="Aditya Kumar";
    ump1[2]=200;
    mp1[14]=1400;
    ump1[0]=0;
    //cout<<ump[1]<<endl;
    //cout<<mp[2]<<endl;
   // cout<<ump[-1]<<endl;
   // cout<<ump[100]<<endl;
    cout<<ump1[2]<<endl;
    cout<<mp1[14]<<endl;
    cout<<mp1[-1]<<endl;
    cout<<ump1[200]<<endl;
    cout<<ump1[0]<<endl;

    return 0;
}