#include<bits/stdc++.h>
using namespace std;
bool checkPalindrome(string str,int l, int u)
{
    int i=l;
    int j=u;
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
bool checkOddPalindromes(string &str)
{
    bool flag=true;
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((j-i+1)%2!=0)
            {
                if(!checkPalindrome(str,i,j))
                {
                    flag=false;
                    break;
                }
            }
        }
    }
    return flag;
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