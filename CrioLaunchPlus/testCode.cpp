#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<x<<endl;
set<string> validState={"AP","AR","AS","BR","CG","GA","GJ","HR","HP",
"JH","PY","LD","LA","JK","DL","DD","CH","AN","KA","KL","MP","MH","MN","ML","MZ","NL","OD","PB","RK","SK","TN","TR"
,"TS","UP","UK","WB"};
bool isAllNumeric(string str)
{
   for(auto &it :str)
    {
        if(it<'0'||it>'9')
        {
            return false;
        }
    }
    return true;
}
bool isAllAlpha(string &str)
{
    for(auto &it :str)
    {
        if(it<'A'||it>'Z')
        {
            return false;
        }
    }
    return true;
}

bool is_valid_number_pattern(string &number) {
        vector<string> token;
        stringstream ss(number);
        string temp;
        while(getline(ss,temp,'-'))
        {
            token.push_back(temp);
        }
        if(token.size()<3)
        {
            return false;
        }
        else if(token.size()==3)
        {
            if(validState.find(token[0])==validState.end())
            {
                return false;
            }
            if(isAllNumeric(token[1])==false)
            {
               return  false;
            }
            if(isAllNumeric(token[2])==false)
            {
                return false;
            }

            return true;
        }
        else if(token.size()==4)
        {

            if(validState.find(token[0])==validState.end())
            {
                
                return false;
            }
            if(isAllNumeric(token[1])==false)
            {
                return false;
            }
            if(isAllAlpha(token[2])==false)
            {
            
                return false;
            }
            if(isAllNumeric(token[3])==false)
            {
                return false;
            }
            return true;

        }

        return false;
}
int main()
{
    string str;
    string temp;
    cin>>str;
    /*stringstream ss(str);
    while(getline(ss,temp,'-'))
    {
        cout<<temp<<endl;
    }*/
    cout<<is_valid_number_pattern(str)<<endl;
    return 0;
}