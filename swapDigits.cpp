#include<bits/stdc++.h>
using namespace std;
void swapDigits(int &A, int &B)
{
    stringstream s1;
    stringstream s2;
    string strA,strB;
    s1<<A;
    s2<<B;
    s1>>strA;
    s2>>strB;
    if(A>B)
    {
        char ch=strA[1];
        strA[1]=strB[0];
        strB[0]=ch;
        cout<<strA<<" +++ "<<strB<<endl;
    }
    else
    {
        char ch=strB[1];
        strB[1]=strA[0];
        strA[0]=ch;
      //  cout<<ch<<endl;
       // cout<<strA<<" ---- "<<strB<<endl;
    }
    stringstream sA(strA);
    stringstream sB(strB);
    sA>>A;
    sB>>B;
    //cout<<A<<" -- "<<B<<endl;
    

    

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B;
        cin>>A>>B;
        int sum1=A+B;
        int t1,u1,t2,u2;
        u1=A%10;
        t1=A/10;
        u2=B%10;
        t2=B/10;
        cout<<t1<<u1<<t2<<u2<<"-- "<<endl;
        int sum2=A+B;
        int s1=0,s2=0;
        if(A>B)
        {
            s1=((t1*10+t2)+(u1*10+u2));
           // s2=((t1*10+t2)+(u1*10+u2))
        }
        else
        {
            s2=((t2*10+t1)+(u2*10+u1));
        }
        
        cout<<max(sum1,max(s1,s2))<<endl;
    }
    return 0;
}