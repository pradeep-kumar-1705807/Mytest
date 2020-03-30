#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k,x;
        int H[26]={0};
        string str;
        cin>>str;
        cin>>k>>x;
        int i,count=0;
        for(i=0;i<str.length();i++)
        {
            if(H[str[i]-'a']<=x)
            {
                H[str[i]-'a']++;
                count++;
            }
            if(H[str[i]-'a']>x && k!=0)
            {
                if(k--)
                {
                    H[str[i]-'a']--;
                }
            }
            else if(H[str[i]-'a']>x && k==0)
            {
                break;
            }
            
            
        }
        cout<<count<<endl;
    }
    return 0;
}