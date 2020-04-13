#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<(long long int)10e9+7<<endl;
    priority_queue<int> pq;
    int n,val;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        pq.push(val);
    }
    while(!pq.empty())
    {
        cout<<pq.top();
        pq.pop();
    }
    return 0;
}