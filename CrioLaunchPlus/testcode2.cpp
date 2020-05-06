#include<bits/stdc++.h>
using namespace std;
bool isNumberValid(string &pattern, string &number)
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


string getCorrectNumber(string &pattern, string &number)
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
int main()
{
    string pattern,number;
    cin>>pattern>>number;
    cout<<getCorrectNumber(pattern,number)<<endl;
    int ans=isNumberValid(pattern,number);
    if(ans==false)
    {
        cout<<getCorrectNumber(pattern,number);
    }
    else
    {
        cout<<"GOOD\n";
    }
    

    return 0;
}