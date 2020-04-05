#include<bits/stdc++.h>
using namespace std;
void solve(string &str, int test) 
{
    string soln="";
    int rightCount=0;
    int first=str[0]-'0';
    for(int i=0;i<first;i++)
    {
        soln+="(";
        rightCount++;
    }
    soln+=str[0];
    for(int i=0;i<str.length()-1;i++)
    {
        int val=str[i+1]-str[i];
        if(val > 0)
        {
            int t=val;
            while(t--)
            {
                soln+="(";
                rightCount++;
            }
            soln+=str[i+1];

        }
        else if(val < 0)
        {
            int t=abs(val);
            while(t--)
            {
                soln+=")";
                rightCount--;
            }
            soln+=str[i+1];
        }
        else if(val==0)
        {
            soln+=str[i+1];
        }
        
    }
    while(rightCount--)
    {
        soln+=")";
    }
    cout<<"Case #"<<test<<": "<<soln<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,testCase;
    cin>>t;
    for( testCase=1;testCase<=t;testCase++)
    {
        string str;
        cin>>str;
        solve(str,testCase);

    }
    return 0;
}