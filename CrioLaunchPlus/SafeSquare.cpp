#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class chess {
    public :
    vector<vector<char>> board;
    int rows,cols;
    vector<vector<int>> mark;

    chess(vector<vector<char> > brd) {
        rows = brd.size();
        cols = brd[0].size();

        for (int i = 0; i < rows; ++i) {
            vector<char> t1(brd[i]);
            vector<int> tmp(cols, 0);
            board.push_back(t1);
            mark.push_back(tmp);
        }
    }

    // TODO: CRIO_TASK_MODULE_SAFE_SQUARE
    // Input:
    //   1) chess board matrix
    // Task:
    //   1) Implement Rook move
    //   2) Implement Bishop move
    //   3) Implement Queens move
    //   4) Implement knight's move
    //   5) Special move
    // Output:
    //   Count the number of safe square and return it
    
  
    int moveQueen(int x, int y)
    {
        //cout<<"Moving Queen \n";
        int n=board.size();
        int m=board[0].size();
        //Marking Current Node
        mark[x][y]=1;
        //up
        int i=x-1;
        int j=y;
        while(i>=0 && board[i][j]=='.')
        {
            mark[i][j]=1;
            i--;
        }
        //down 
        i=x+1;
        j=y;
        while(i<n && board[i][j]=='.')
        {
            mark[i][j]=1;
            i++;
        }
        //left
        i=x;
        j=y-1;
        while(j>=0 && board[i][j]=='.')
        {
            mark[i][j]=1;
            j--;
        }
        //right
        i=x;
        j=y+1;
        while(j<m && board[i][j]=='.')
        {
            mark[i][j]=1;
            j++;
        }
        //right up
        i=x-1;
        j=y+1;
        while(i>=0 && j<m && board[i][j] == '.')
        {
            mark[i][j]=1;
            j++;
            i--;
        }
        //left up
        i=x-1;
        j=y-1;
        while(i>=0 && j<m && board[i][j] == '.')
        {
            mark[i][j]=1;
            j--;
            i--;
        }
        //right down
        i=x+1;
        j=y+1;
        while(i<n && j<m && board[i][j] == '.')
        {
            mark[i][j]=1;
            j++;
            i++;
        }
        //left  down
        i=x+1;
        j=y-1;
        while(i<n && j>=0 && board[i][j] == '.')
        {
            mark[i][j]=1;
            j--;
            i++;
        }
    }
    void moveRook(int x,int y)
    {
        //cout<<"Moving Rook \n";
        int n=board.size();
        int m=board[0].size();
        //Marking Current Node
        mark[x][y]=1;
        //up
        int i=x-1;
        int j=y;
        while(i>=0 && board[i][j]=='.')
        {
            mark[i][j]=1;
            i--;
        }
        //down 
        i=x+1;
        j=y;
        while(i<n && board[i][j]=='.')
        {
            mark[i][j]=1;
            i++;
        }
        //left
        i=x;
        j=y-1;
        while(j>=0 && board[i][j]=='.')
        {
            mark[i][j]=1;
            j--;
        }
        //right
        i=x;
        j=y+1;
        while(j<m && board[i][j]=='.')
        {
            mark[i][j]=1;
            j++;
        }

    }
    void moveBishop(int x, int y)
    {
       // cout<<"Moving Bishop \n";
        int n=board.size();
        int m=board[0].size();
        //Marking Current Node
        mark[x][y]=1;
         //right up
        int i=x-1;
        int j=y+1;
        while(i>=0 && j<m && board[i][j] == '.')
        {
            mark[i][j]=1;
            j++;
            i--;
        }
        //left up
        i=x-1;
        j=y-1;
        while(i>=0 && j<m && board[i][j] == '.')
        {
            mark[i][j]=1;
            j--;
            i--;
        }
        //right down
        i=x+1;
        j=y+1;
        while(i<n && j<m && board[i][j] == '.')
        {
            mark[i][j]=1;
            j++;
            i++;
        }
        //left  down
        i=x+1;
        j=y-1;
        while(i<n && j>=0 && board[i][j] == '.')
        {
            mark[i][j]=1;
            j--;
            i++;
        }

    }
    void moveKnight(int x , int y)
    {
        // cout<<"Moving Bishop \n";
        int n=board.size();
        int m=board[0].size();
        int i,j;
        mark[x][y]=1;
        //up left
        i=x-2;
        j=y-1;
        if(i>=0 && j>=0 &&board[i][j]=='.')
        {
            mark[i][j] = 1;
        }

        //up right
        i=x-2;
        j=y+1;
        if(i>=0 && j<m &&board[i][j]=='.')
        {
            mark[i][j] = 1;
        }
        //down left
        i=x+2;
        j=y+1;

        if(i<n && j<m &&board[i][j]=='.')
        {
            mark[i][j] = 1;
        }

        //down  right
        i=x+2;
        j=y-1;

        if(i<n && j>=0 &&board[i][j]=='.')
        {
            mark[i][j] = 1;
        }

        //left up
        i=x+1;
        j=y-2;

        if(i<n && j>=0 &&board[i][j]=='.')
        {
            mark[i][j] = 1;
        }

        //left down
        i=x-1;
        j=y-2;

        if(i>=0 && j>=0 &&board[i][j]=='.')
        {
            mark[i][j] = 1;
        }
        //right up
        i=x+1;
        j=y+2;


        if(i<n && j<m &&board[i][j]=='.')
        {
            mark[i][j] = 1;
        }

        //right down
        i=x-1;
        j=y+2;

        if(i>=0 && j<m &&board[i][j]=='.')
        {
            mark[i][j] = 1;
        }
    }
    void moveSpecialPeice(int x, int y)
    {
        int n=board.size();
        int m=board[0].size();
        int dist_x=min(abs(x-0),abs(n-1-x));
        int dist_y=min(y-0,abs(m-1-y));
        int layerId=min(dist_x,dist_y);
        mark[x][y]=1;
        int u=layerId;
        cout<<"Layer Id "<<u<<endl;
        for(int i=u;i<n-u;i++)
        {
            mark[i][u]=1;
        }
        for(int i=u;i<m-u;i++)
        {
            mark[u][i]=1;
        }
        for(int i=u;i<n-u;i++)
        {
            mark[i][m-u-1]=1;
        }
        for(int i=u;i<m-u;i++)
        {
            mark[n-u-1][i]=1;
        }
    }
    int move() {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='Q')
                {
                    moveQueen(i,j);
                }
                else if(board[i][j] == 'R')
                {
                    moveRook(i,j);
                }
                else if(board[i][j]=='B')
                {
                    moveBishop(i,j);
                }
                else if(board[i][j]=='K')
                {
                    moveKnight(i,j);
                }
                else if(board[i][j]=='S')
                {
                    moveSpecialPeice(i,j);
                }
            }
        }
        int count=0;
        for(auto &it :  mark)
        {
            for(auto &jt : it)
            {
                if(jt == 0)
                {
                    count++;
                }
            }
        }
        return count;
    }


};
template<typename T>
void __pM(vector<vector<T>> &vp)
{
    for(auto &it : vp)
    {
        for(auto &jt : it)
        {
            cout<<jt<<" ";
        }
        cout<<endl;
    }
}
int main()
{
   
    int rows,cols;
    vector<vector<char>> board;
	cin >> rows >> cols;
	board.resize(rows,vector<char>(cols));
	for(int i = 0 ; i< rows ; i++) {
		for(int j = 0 ;j < cols ; j++) {
			cin >> board[i][j];
		}
	}
    chess chess_board(board);

	cout <<"Ans :) "<<chess_board.move() << endl;
    __pM(chess_board.mark);
    
	return 0;
}

