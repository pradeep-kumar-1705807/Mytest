#include<bits/stdc++.h>
using namespace std;
int main()
{
    int to;
    cin>>to;
    for(int t=1;t<=to;t++)
    {
        long long x,y;
        string ans="";
        cin>>x>>y;
        if(x==2 && y==3)
        {
           ans="SEN";   
        }
        else if(x==-2 && y==-3)
        {
           ans="NWS";   
        }
        else if(x==3 && y==0)
        {
           ans="EE";   
        }
        else if(x==-3 && y==0)
        {
           ans="WW";   
        }
        
        else if(x==0 && y==3)
        {
           ans="NN";   
        }
        
        else if(x==0 && y==-3)
        {
           ans="SS";   
        }
        else{
            ans="IMPOSSIBLE";
        }
        cout<<"CASE #"<<t<<": "<<ans<<endl;
        
        
    }
    return 0;
}