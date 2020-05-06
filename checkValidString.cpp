#include<bits/stdc++.h>
using namespace std;
bool checkValid(string &s) 
{
    bool ans=true;
    int i=0,p=0,star=0;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        if(p==0 && s[i]==')' && star==0)
        {
            ans=false;
            break;
        }
        else if(s[i]=='*')
        {
            star++;
        }
        else if(s[i]=='(')
        {
            p++;
        }
        else if(s[i]==')')
        {
            if(p==0 && star ==0)
            {
                ans=false;
                break;
            }
            else if(p==0 && star > 0)
            {
                star--;
            }
            else if(p>0)
            {
                p--;
            }
        }
        else {
            ans=false;
            break;
        }
    }
    if(p!=0)
    {
        if(star < p)
        {
            ans=false;
        }
    }
    return ans;
        
}
bool checkValidString(string &str)
{
    string rev=str;
    reverse(rev.begin(), rev.end());
    for(auto &it : rev)
    {
       if(it==')')
        {
            it='(';
        }
       else if(it == '(')
        {
             it=')';
        }
    }
    return (checkValid(str)&&checkValid(rev));
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout<<str<<"  "<<checkValidString(str)<<endl;
    }
    return 0;
}