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
            ans=s2;
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
            ans=s1;
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
int main()
{
    int t;
    cin>>t;
    while(t--){
    string s1,s2;
    cin>>s1>>s2;
    cout<<maxString(s1,s2)<<endl;
    }
    return 0;
}