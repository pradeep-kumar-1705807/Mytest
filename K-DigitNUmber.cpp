#include<bits/stdc++.h>
using namespace std;
string maxString(string &s1, string &s2)
{
    string temp;
    if(s1.length()==s2.length())
    {
        if(s1>s2)
        {
            return s1;
        }
        else
        {
            return s2;
        }
        
    }
    int diff =s1.length()-s2.length();
    diff=abs(diff);
    string ans="";
    for(int i=0;i<diff;i++)
    {
        temp+='0';
    }
    if(s1.length() > s2.length())
    {
        temp+=s2;
        if(temp==s1)
        {
            ans=s1;
        }
        else if(temp > s1)
        {
            ans=s2;
        }
        else 
        {
            ans= s1;
        }
    }    
    else if(s1.length()<s2.length())
    {
        temp+=s1;
        if(temp==s2)
        {
            ans=s2;
        }
        else if(temp > s2)
        {
            ans= s1;
        }
        else{
            ans= s2;
        }
    }

    return ans;
}

string solve(string &str, int k, int index, int len, vector<string> &dp)
{

    if(index == str.length()-1)
    {
        return string(1,str[str.length()-1]);
    }
    if(len==k)
    {
        char ch=char(0);
        for(int i=len+1;i<str.length();i++)
        {
            if(ch<str[i])
            {
                ch=str[i];
            }
        }
        return string(1,ch);
    }
    if(dp[index]!="")
    {
        return dp[index];
    }
    string ans1="",ans2="";
    ans1=str[index]+solve(str,k,index+1,len+1,dp);
    ans2=solve(str,k,index+1,len,dp);
    dp[index] = maxString(ans1,ans2);
    return dp[index];
}
string getMaxDigit(string &str, int k)
{
    vector<string> dp(str.length(),"");
    string ans =solve(str,k,0,1,dp);
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    string str;
    int k;
    cin>>str>>k;
    cout<<getMaxDigit(str,k)<<endl;
    }
    return 0;
}