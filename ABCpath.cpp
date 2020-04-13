#include<bits/stdc++.h>
using namespace std;
int dfs(char **grid, int x, int y,int n, int m ,int **visited) 
{
    cout<<x<<" -- "<<y<<endl;
    if(x<0||y<0 ||x>=n||y>=m||visited[x][y]==1)
    {
        return 0;
    }
    visited[x][y]=1;
    char val=grid[x][y];
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;
   // cout<<x<<" -- "<<y<<endl;
    if(x+1<n && grid[x+1][y]==val+1)
    {
        a = 1+dfs(grid,x+1, y, n, m ,visited);
    }
    else if(x-1>=0 && grid[x-1][y]==val+1)
    {
        b = 1+dfs(grid,x-1, y, n, m ,visited);
    }
    else if(y+1<m && grid[x][y+1]==val+1)
    {
        c = 1+dfs(grid,x, y+1, n, m ,visited);
    }
    else if(y-1>=0 && grid[x][y-1]==val+1)
    {
        d = 1+dfs(grid,x, y-1, n, m ,visited);
    }
    else if(x+1<n&&y+1<m && grid[x+1][y+1]==val+1)
    {
        e = 1+dfs(grid,x+1, y+1, n, m ,visited);
    }
    else if(x+1<n &&y-1>=0 &&grid[x+1][y-1]==val+1)
    {
        f = 1+dfs(grid,x+1, y-1, n, m ,visited);
    }
    else if(x-1>=0 &&y+1<m&& grid[x-1][y+1]==val+1)
    {
        g = 1+dfs(grid,x-1, y+1, n, m ,visited);
    }
    else if(x-1>=0 &&y-1>=0 &&grid[x-1][y-1]==val+1)
    {
        h = 1+dfs(grid,x-1, y-1, n, m ,visited);
    }
    else{
        return 1;
    }
    visited[x][y]=0;

    return max({a,b,c,d,e,f,g,h});
}
int findPath(char** grid, int n, int m)
{
    int **visited=new int*[n];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        visited[i]= new int[m];
        for(int j=0;j<m;j++)
        {
            visited[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]=='A' && visited[i][j]==0)
            {
                int val=dfs(grid,i,j,n,m,visited);
                ans=max(ans,val);
            }
        }        
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    char **grid= new char*[n];
    for(int i=0;i<n;i++)
    {
        grid[i]=new char[m];
        cin>>grid[i];
    }
    cout<<findPath(grid, m,n);

}