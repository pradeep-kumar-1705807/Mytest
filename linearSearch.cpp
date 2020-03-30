#include<bits/stdc++.h>
using namespace std;

int search(int A[], int n, int x)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        if(A[i]==x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    
    int *A=new int[n];

    char *str=new char[n];
    char str1[1000];




    string str;
    cin>>str;





/*   To input a line with space */
    string s1;
    getline(cin,str);








    for(int i=0;i<n;i++)
    {
        cin>>A[i];

    }
    int target;
    cin>>target;
    int result=search(A,n,target);
    cout<<result<<endl;
}