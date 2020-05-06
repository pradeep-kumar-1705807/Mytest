#include<bits/stdc++.h>
using namespace std;
set<string> validState={"AP","AR","AS","BR","CG","GA","GJ","HR","HP",
"JH","PY","LD","LA","RJ","JK","DL","DD","CH","AN","KA","KL","MP","MH","MN","ML","MZ","NL","OD","PB","RK","SK","TN","TR"
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

map<string , string> patternsMap;

struct number_pattern {
    string pattern;
    string type;
    

    number_pattern() {}
    number_pattern( string & p,  string & t)
    {
        
        this->pattern=p;
        this->type=t;
    }

    number_pattern(const number_pattern & other) {
    }

    bool isNumberValid(string &pattern,const string &number)
{
    int i=0;
    int index=0;
    if(number.size()!=4)
    {
        return false;
    }
    while(i<pattern.length())
    {
        if(pattern[i+1]!='-')
        {
            if(number[index]!=pattern[i])
            {
                return false;
            }
            i++;
        }
        else if(pattern[i+1]=='-')
        {
            if(number[index]<pattern[i] || number[index]>pattern[i+2])
            {
                return false;
            }
            i+=3;
        }
        index++;
    }
    return true;
}


    bool number_matches_the_pattern(const string & number) {
        
       return isNumberValid(pattern,number);

    }

    string getCorrectNumber(string pattern, string number)
    {
        int i=0;
        int index=0;
        while(i<pattern.length())
        {
            if(pattern[i+1]!='-')
            {
                if(number[index]!=pattern[i])
                {
                    number[index]=pattern[i];
                }
                i++;
            }
            else if(pattern[i+1]=='-')
            {
                if(number[index]<pattern[i] || number[index]>pattern[i+2])
                {
                    number[index]=pattern[i];
                }
                i+=3;
            }
            index++;
        }
        return number;
    }
};


struct vehicle_info {
    string number;
    string type;
    string patternNumber;

    vehicle_info(const string & number, string type = "optional") {
        this->number = number;
        this->type = type;
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
                return true;
            }
            if(isAllNumeric(token[1])==false)
            {
               return  false;
            }
            if(isAllNumeric(token[2])==false)
            {
                return false;
            }
            patternNumber=token[2];
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
            patternNumber=token[3];
            return true;

        }

        return false;
    }
};

bool is_palindrome(const string & s)
{
    int i=0;
    int j=s.length()-1;
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void lucky_number(vector<vehicle_info> & vehicles, vector<number_pattern> & patterns)
{
    patternsMap["car"]="0-90-90-90-9";
    patternsMap["bus"]="0-90-90-90-9";
    patternsMap["motobike"]="0-90-90-90-9";
    patternsMap["truck"]="0-90-90-90-9";

    for(auto &it : patterns)
    {
        patternsMap[it.type]=it.pattern;
    }

    vector<vehicle_info> luckyVehicles;
    for(auto &it : vehicles)
    {
        if(it.is_valid_number_pattern(it.number)==true )
        {
            cout<<"Yes ";

            number_pattern n1(patternsMap[it.type],it.type);
            if(n1.number_matches_the_pattern(it.patternNumber)==true)
            {
                if(is_palindrome(it.patternNumber)==true)
                {
                    luckyVehicles.push_back(it);
                }
                cout<<"Good ";
            }
            else
            {
                string correctNumber = n1.get_number_suggestion(it.patternNumber);
                if(is_palindrome(correctNumber))
                {
                    luckyVehicles.push_back(it);
                }
                cout<<"Bad "<<correctNumber;
            }
            cout<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    cout<<luckyVehicles.size()<<endl;
    for(auto &it : luckyVehicles)
    {
        cout<<it.number<<" "<<it.type<<endl;
    }
}



// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE




int main()
{
    int n;
    cin >> n;


    vector<number_pattern> patterns(n);
    for (int i = 0; i < n; ++i) {
        
        cin>>patterns[i].type>>patterns[i].pattern;
    }

    int m;
    cin >> m;
    vector<vehicle_info> vehicles;
    for (int i = 0; i < m; ++i) {
        string type;
        string number;

        cin >> number >> type;

        vehicle_info info(number, type);
        vehicles.push_back(info);
    }

    lucky_number(vehicles, patterns);
    return 0;
}

