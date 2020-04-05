#include<bits/stdc++.h>
using namespace std;
struct Activity
{
    int id;
    int startTime;
    int endTime;
    char person;
};
void solve(string &str, int test) 
{
}
bool compStartTime(Activity &a1, Activity &a2)
{
    if(a1.startTime < a2.startTime )
    {  
        return true;
    }
    return false;
}
bool compEndTime(Activity &a1, Activity &a2)
{
    if(a1.endTime < a2.endTime )
    {  
        return true;
    }
    return false;
}

bool compById(Activity &a1, Activity &a2)
{
    if(a1.id < a2.id )
    {  
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,testCase;
    cin>>t;
    for( testCase=1;testCase<=t;testCase++)
    {
        int n;
        cin>>n;
        int lastC=0, lastJ=0;
        vector<Activity> A(n);
        for(int i=0;i<n;i++)
        {
            A[i].id=i+1;
            cin>>A[i].startTime>>A[i].endTime;
            A[i].person='F';
        }
        sort(A.begin(),A.end(),compStartTime);
        //sort(A.begin()+1,A.end(),compEndTime);
        A[0].person='C';
        lastC=A[0].endTime;
        for(int i=0;i<n-1;i++)
        {
            if(A[i+1].startTime >= lastC)
            {
                A[i+1].person='C';
                lastC=A[i+1].endTime;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(A[i].person=='F')
            {
                lastJ=A[i].endTime;
                A[i].person='J';
                break;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(A[i+1].person=='F' && A[i+1].startTime >= lastJ)
            {
                A[i+1].person='J';
                lastJ=A[i+1].endTime;
            }
        }
        bool impossible=false;
        for(int i=0;i<n;i++)
        {
            if(A[i].person=='F')
            {
                impossible=true;
                break;
            }
        }
        string soln="";
        if(impossible==true)
        {
            cout<<"Case #"<<testCase<<": "<<"IMPOSSIBLE"<<endl;
        }
        else
        {
            sort(A.begin(),A.end(),compById);
            for(int i=0;i<n;i++)
            {
                soln+=A[i].person;
            }
            cout<<"Case #"<<testCase<<": "<<soln<<endl;
        }
    }
    return 0;
}