#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> & matrix, int t)
{
    int n=matrix.size();
    int k=0,r=0,c=0;
    for(int i=0;i<n;i++)
    {
        k+=matrix[i][i];
    }
    for(int i=0;i<n;i++)
    {
        int hashRow[1001]={0};
        int hashCol[1001]={0};
        bool flagRow=false,flagCol=false;
        for(int j=0;j<n;j++)
        {
            hashRow[matrix[i][j]]++;
            hashCol[matrix[j][i]]++;
        }
        for(int j=0;j<101;j++)
        {
            if(hashRow[j]>1)
            {
                flagRow=true;
            }
            if(hashCol[j]>1)
            {
                flagCol=true;
            }

        }
        if(flagRow)
        {
            r++;
        }
        if(flagCol)
        {
            c++;
        }
    }
    printf("Case #%d: %d %d %d\n",t,k,r,c);
}

int main()
{
    int t;
    cin>>t;
    for( int k=1;k<=t;k++)
    {
        int n,val,target;
        cin>>n;
        vector<vector<int>> matrix(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>val;
                matrix[i].push_back(val);
            }
        }
        solve(matrix,k);
    }
    return 0;
}