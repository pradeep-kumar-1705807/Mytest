#include<bits/stdc++.h>
using namespace std;
string max(string &s1 , string &s2)
{
    if(s1.length()>s2.length())
    {
        return s1;
    }
    else if(s1.length()==s2.length())
    {
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]>s2[i])
            {
                return s1;   
            }
        }
    }
    return s2;
}

string solve(string &str, int k, int index, int len)
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
        return string(1,ch);;
    }
    string ans1="",ans2="";
    ans1=str[index]+solve(str,k,index+1,len+1);
    ans2=solve(str,k,index+1,len);
    return max(ans1,ans2);
}
string getMaxDigit(string &str, int k)
{
    string ans =solve(str,k,0,1);
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