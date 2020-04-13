#include<bits/stdc++.h>
using namespace std;

bool check(int Hash[], int pattern[])
{
    for(int i=0;i<26;i++)
    {
        if(Hash[i] < pattern[i] )
        {
            return false;
        }
    }
    return true;
}

string minWindow(string &S, string &T) {
    int l=0;
    int Hash[26]={0};
    int pattern[26]={0};
    for(auto &it : T) 
    {
        pattern[it-'A']++;
    }
    for( l=0;l<S.length();l++)
    {
        if(S[l] == T[0])
        {
            break;
        }
    }
    int i=l,j=l;
    int ans=(int)10e9;
    while(i<S.size() && j<S.size())
    {
        while(i<j && check(Hash,pattern) == true )
        {
            if(pattern[S[i]-'A'] > 0)
            {
                Hash[S[i]-'A']--;
            }
            i++;
        }
        while(j<S.size() && check(Hash,pattern) == false)
        {
            if(pattern[S[i]-'A'] > 0)
            {
                Hash[S[j]-'A']++;
            }
            j++;
        }
        int  val=j-i+1;
        if(ans>val)
        {
            ans=val;
        }
    }
    cout<<ans;
    return "";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S,T;
        cin>>S>>T;
        cout<<minWindow(S,T)<<endl;
    }
    return 0;
}