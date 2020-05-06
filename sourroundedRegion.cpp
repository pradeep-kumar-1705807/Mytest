#include<bits/stdc++.h>
using namespace std;
bool checkBoundryReachable(vector<vector<char>> &board , int x , int y, vector<vector<char>> &visited)
{
    if(x<0||y<0||x>=board.size()||y>=board[0].size()||visited[x][y]=='N'||board[x][y]=='X')
    {
        return false;
    }
    if((x==0||y==0||x==board.size()-1||y==board[0].size()-1)&&board[x][y]=='O')
    {
        return true;
    }
    visited[x][y]='N';
    bool up    = checkBoundryReachable(board,x-1,y,visited);
    bool down  = checkBoundryReachable(board,x+1,y,visited);
    bool left  = checkBoundryReachable(board,x,y-1,visited);
    bool right = checkBoundryReachable(board,x,y+1,visited);
    if(up||down||left||right)
    {
        visited[x][y]='G';
        return true;
    }
    return false;
}
void putX(vector<vector<char>> &board,int x, int y)
{
    if(x<1||y<1||x>board.size()-2||y>board[0].size()-2||board[x][y] == 'X')
    {
        return ;
    }
    board[x][y]='X';
    putX(board, x-1, y);
    putX(board, x+1, y);
    putX(board, x, y-1);
    putX(board, x, y+1);
    return ;
}
void solve(vector<vector<char>>& board) {
    if(board.size()==0)
    {
        return ;
    }
    int i,j;
    int n = board.size();
    int m = board[0].size();
    vector<vector<char>> visited(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            visited[i].push_back('G');
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(board[i][j] == 'O' && visited[i][j]== 'G')
            {
                bool ans= checkBoundryReachable(board,i,j,visited);
                if(ans == false)
                {
                    putX(board,i,j);
                }
            }
        }
    }     
}
int main()
{
    int t;
   // cin>>t;
    int n,m;
    cin>>n>>m;
    vector<vector<char>> board(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char ch;
            cin>>ch;
            board[i].push_back(ch);
        }
    }
    solve(board);
    cout<<" --------------- "<<endl;
    for(auto &it : board)
    {
        for(auto &jt : it)
        {
            cout<<jt<<" ";
        }
        cout<<endl;
    }
    return 0;
}