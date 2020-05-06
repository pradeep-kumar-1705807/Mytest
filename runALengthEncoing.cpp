#include<bits/stdc++.h>
using namespace std;
string runLengthEncoding(string &str)
{
    int i=0;
    int n=str.length();
    string ans="";
    while(i<n)
    {
        int count=0;
        ans+= str[i];
        int j=i;
        while(str[i]==str[j] && j<n)
        {
            count++;
            j++;
        }
        ans+= to_string(count);
        i=j;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string  str;
        cin>>str;
        cout<<runLengthEncoding(str)<<endl;
    }
    return 0;
}