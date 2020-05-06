#include<bits/stdc++.h>
using namespace std;;
int dfs(vector<vector<char>> &grid, int x, int y ,vector<vector<bool>> &visited)
    {
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||visited[x][y]==true || grid[x][y] =='0')
        {
            return 0;
        }
        visited[x][y]=true;
        int up=0,down=0,right=0,left=0;
        up=dfs(grid,x-1,y,visited);
        down=dfs(grid,x+1,y,visited);
        left=dfs(grid,x,y-1,visited);
        right=dfs(grid,x,y+1,visited);
        return 1+up+down+left+right;
    }
int numIslands(vector<vector<char>>& grid) {
    int i,j;
    int count=0;
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<bool>> visited(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            visited[i].push_back(false);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='1' && visited[i][j]==false)
            {
                count++;
                int ans=dfs(grid,i,j,visited);
                cout<<"Ans :) "<<ans<<"--\n";
                if(ans>0)
                {
                   // count++;
                }
            }
        }
    }
    return count;
}
int main()
{
    int t=1;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char>> grid(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char val;
                cin>>val;
                grid[i].push_back(val);
            }
        }
        cout<<numIslands(grid);
    }

    return 0;
}