#include<bits/stdc++.h>
using namespace std;
typedef pair<int , int> pi;
pi getTheThird(vector<int> &A,int ind, int a , pi &p1, int &nr)
{
    pi result;
    int index =  p1.second;
    for(int i=ind+1;i<index;i++)
    {
        if(A[i]>a && A[i]>p1.first)
        {
          //  cout<<"hi";
            nr=1;
            result.first=A[i];
            result.second=i;
            return result;
        }
    }
    for(int i=index+1;i<A.size();i++)
    {
        if(A[i]<a && A[i]> p1.first)
        {
           // cout<<"hi2";
            nr=2;
            result.first=A[i];
            result.second=i;
            return result;
        }
    }
    nr=0;
    return  result;
}
void print(vector<int> &A)
{
    for(auto &it : A)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> A(n+1);
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(int i=1;i<=n;i++)
        {
            cin>>A[i];
            pq.push(make_pair(A[i],i));
        }
        vector<pair<int, vector<int>>> result;
        for(int i=1;i<=n;i++)
        {
            if(A[i]!=i)
            {
                int nr=1;
                pair<int, int> tempPair1 =  pq.top();
                pq.pop();
                pair<int, int> tempPair2 = getTheThird(A,i,A[i],tempPair1,nr);
                if(nr==0)
                {
                    break;
                }
                vector<int> vp ={i,tempPair1.second,tempPair2.second};
              //  print(vp);
                k=k-nr;

                A[i]=vp[0];
                A[tempPair1.second]=vp[1];
                A[tempPair2.second]=vp[2];
                result.push_back(make_pair(nr,vp));

            }
            else{
                pq.pop();
            }
            if(k<=0)
            {
                break;
            }
        }

        if(is_sorted(A.begin()+1,A.end())==true)
        {
            if(result.size()==0){
                cout<<0<<endl;
            }
            else{
            for(auto &it : result)
            {
                cout<<it.first<<endl;
                print(it.second);
            }
            }
        }
        else
        {
            cout<<"-1";
        }
    }
    return 0;
}