#include <iostream>
#include <bits/stdc++.h>
using namespace std;
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
    
    
 
    
    int move() {
        int n=board.size();
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='Q')
                {
                    moveQueen(i,j);
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
       // __pM(mark);
        return n*n-count-1;
    }


};

int main()
{
   
    int n,k;
    vector<vector<char>> board;
	cin >> n >> k;
	board.resize(n,vector<char>(n));
	for(int i = 0 ; i< n ; i++) {
		for(int j = 0 ;j < n ; j++) {
			board[i][j]='.';
		}
	}
    int qx,qy;
    cin>>qx>>qy;
    board[qx-1][qy-1]='Q';
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        board[x-1][y-1]='R';
    }
    chess chess_board(board);

	cout<<chess_board.move() << endl;
    
	return 0;
}

