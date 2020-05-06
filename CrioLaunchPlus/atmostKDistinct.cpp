#include<bits/stdc++.h>
using namespace std;

// Implement your solution here
int lengthOfLongestSubstringKDistinct(string &s, int k) {
	int n=s.length();
	if(n==0 || k==0)
	{
		return 0;
	}
	int longestSubstring = 0;
    int first=0,second=0;
    map<char, int> characterMap;
    while(second < n)
	{
		if(characterMap.size() <= (unsigned int) k)
		{
			characterMap[s[second]]++;
            second++;
		}
		if(characterMap.size()>k)
		{
            characterMap[s[first]]--;
			if(characterMap[s[first]]==0)
			{
				characterMap.erase(s[first]);
			}
			first++;
		}
		if(first == 0 && second == n && characterMap.size() > k)
		{
			longestSubstring = max(longestSubstring, second-first -1);	
		}
		else{
        longestSubstring = max(longestSubstring, second-first);
		}
	}
	return longestSubstring;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	int answer = lengthOfLongestSubstringKDistinct(s,k);
	cout <<  answer<<endl;
    }
	return 0;
}
