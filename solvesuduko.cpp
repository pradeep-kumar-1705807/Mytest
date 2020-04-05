#include<bits/stdc++.h>
using namespace std;
bool findEmptyLocation(int **grid, int &row, int &col, int N)
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(grid[i][j]==0)
			{
				row=i;
				col=j;
				return true;
			}
		}
	}
	return false;
}
bool isSafeInRow(int **grid, int row, int num,int N)
{
	for(int i=1;i<=;i++)
	{
		if(grid[row][i]==num)
		{
			return false;
		}

	}
	return true;

}
bool isSafeInCol(int **grid, int col, int num, int N)
{
	for(int i=1;i<=N;i++)
	{
		if(grid[i][col]==num)
		{
			return false;
		}
	}
	return true;

}

bool isSafe(int **grid,int row, int col,int num, int N)
{
	if(isSafeInRow(grid,row,num,N)&&isSafeInCol(grid,col,num,N))
	return true;
   return false;
}


bool sudokuSolver(int **grid, int N)
{
	int row=1,col=1;
	if(!findEmptyLocation(grid,row,col,N))
	{
		return true;
	}
	for(int i=1;i<=9;i++)
	{
		if(isSafe(grid,row,col,i,N)){
			grid[row][col]=i;
			if(sudokuSolver(grid,N))
				return true;
			grid[row][col]=0;
		}
	}
	return false;

}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
	int **grid= new int*[N+1];
	for(int i=0;i<=N;i++)
	{
        grid[i]= new int[N+1];
		for(int j=0;j<=N;j++)
		{
			grid[i][j]=0;
		}
	}
	sudokuSolver(grid,N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
    }
	return 0;
}
