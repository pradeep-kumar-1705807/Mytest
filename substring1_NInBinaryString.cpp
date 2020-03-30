#include<bits/stdc++.h>
using namespace std;

bool queryString(string S, int N) {
    bitset<64> b1(N);
    string pattern;
    int index=0;
    for(int i=0;i<64;i++)
    {
        if(b1[i]==1)
        {
            index=i;
        }
    }
    for(int i=0;i<=index;i++)
    {
        pattern+=char(b1[i]+'0');
    }
    reverse(pattern.begin(),pattern.end());
    int ans = match_pattern(S,pattern);
    return ans;
    
}
int main()
{
    string S;
    int N;
    cin>>S>>N;
    cout<<queryString(S,N)<<endl;
    return 0;

}       
        
    