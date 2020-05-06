#include<bits/stdc++.h>
using namespace std;
bool getLength(vector<vector<char>> &matrix, int x, int y, vector<vector<bool>> visited, int &count)
{
    if(x<0||y<0||x>=matrix.size()||y>=matrix[0].size()||matrix[x][y]==0)
    {
        return false;
    }
    if(visited[x][y]==true && matrix[x][y] ==1)
    {
        return true;
    }
    visited[x][y]=true;
    bool down=false;
    bool right=false;
    bool dia=false;
    down  = getLength(matrix,x+1,y,visited,count);
    right = getLength(matrix,x,y+1,visited,count);
    dia   = getLength(matrix,x+1,y+1,visited,count);
    if(down == true && right ==true && dia ==true)
    {
        count++;
        return true;
    }
    visited[x][y]=false;
    return false;

}
int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<bool>> visited(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            visited[i].push_back(false);
        }
    }
    int max=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==true)
            {
                int ans = 1;
                getLength(matrix,i,j,visited,ans);
                if(max<ans)
                {
                    max=ans;
                }
            }
        }
    }
    return max*max;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> vp(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char ch;
            cin>>ch;
            vp[i].push_back(ch);
        }
    }
    cout<<maximalSquare(vp);
    
    return 0;
}