#include<bits/stdc++.h>
using namespace std;
bool sortByAnagram(string s1, string s2)
{
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2)
    {
        return true;
    }
    return false;
}
/*vector<vector<string>> groupAnagrams1(vector<string>& strs) {
    vector<string> str
    vector<vector<string>> soln;
    int n=strs.size();
    if(n==0)
    {
        return soln;
    }
     sort(strs.begin(),strs.end());
    sort(strs.begin(),strs.end(),sortByAnagram);
    /*for( auto &it : strs)
    {
        cout<<it<<" ";
    }
    soln.push_back(vector<string>());
    int k=0;
    for(int i=0;i<n-1;i++)
    {
        if(sortByAnagram(strs[i],strs[i+1])== true)
        {
            soln[k].push_back(strs[i]);
        }
        else
        {
            soln[k].push_back(strs[i]);
            k++;
            soln.push_back(vector<string>());
        }
    }
    soln[k].push_back(strs[n-1]);
  
    
    return soln;
}*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<pair<string , string>> tempSrs;
    vector<vector<string>> soln;
    int n=strs.size();
    if(n==0)
    {
        return soln;
    }
    for(auto &it : strs)
    {
        string s=it;
        sort(s.begin(),s.end());
        tempSrs.push_back(make_pair(s,it));
    }
    sort(tempSrs.begin(),tempSrs.end());
    soln.push_back(vector<string>());
    int k=0;
    for(int i=0;i<n-1;i++)
    {
        if(tempSrs[i].first==tempSrs[i+1].first)
        {
            soln[k].push_back(tempSrs[i].second);
        }
        else
        {
            soln[k].push_back(tempSrs[i].second);
            k++;
            soln.push_back(vector<string>());
        }
    }
    soln[k].push_back(tempSrs[n-1].second);
  
    
    return soln;
}


int main()
{
    int n;
    cin>>n;
    vector<string> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    vector<vector<string>> soln=groupAnagrams(A);
    for(auto &it : soln)
    {
        for(auto &jt : it)
        {
            cout<<jt<<" ";
        }
        cout<<endl;
    }
}
