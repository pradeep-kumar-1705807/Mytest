//Need time to understand the problemls


#include<bits/stdc++.h>
using namespace std;
bool checkAssigned(int i, int j, int mask, int N)
{
    vector<int> vp;
    for(int k=1;k<=N;k++)
    {
        if( (mask&(1<<k)) !=0)
        {
            vp.push_back(k);
        }

    }
    for(auto &it : vp)
    {
        if(it==j)
        {
            return true;
        }
    }
    return false;
}
int fun1(int mask, int N)
{
    if(mask==(1<<N)-2)
    {
        cout<<"hi"<<endl;
        return 1;
    }
    int ans=0;
    for(int i=1;i<=N;i++)
    {
        if((mask & (1<<i)) ==0)
        {
            for(int j=1;j<=N;j++)
            {
                //cout<<i<<" -- "<<j<<" -- "<<(i&j)<<endl;
                if( (i & j)== i && checkAssigned(i,j,mask,N)==false)
                {
                    cout<<i;
                    ans+=fun1(mask|(1<<i),N);
                }

            }
            cout<<endl;
        }
    }
    return ans;
}
int main()
{
    int N;
    cin>>N;
    int mask=0;
    cout<<fun1(mask,N)<<"\n";
    return 0;
}