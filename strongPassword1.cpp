#include<bits/stdc++.h>
using namespace std;
bool checkOddPalindromes(string str)
{
    if(str.length()<3)
    {
        return false;
    }
    for(int i=0,j=2;j<str.length();i+=2,j+=2)
    {
        if(str[i]!=str[j])
        {
            return false;
        }
    }
     for(int i=1,j=3;j<str.length();i+=2,j+=2)
    {
        if(str[i]!=str[j])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        if(checkOddPalindromes(str))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}