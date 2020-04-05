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
	for(int i=1;i<=N;i++)
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
bool checkTrace(int **grid, int N, int target)
{
    int sum=0;
    for(int i=1;i<=N;i++)
    {
        sum+=grid[i][i];
    }
    if(sum==target)
    {
        return true;
    }
    return false;
}

bool sudokuSolver(int **grid, int N,int target)
{
	int row=1,col=1;
	if(!findEmptyLocation(grid,row,col,N))
	{
        if(checkTrace(grid,N,target)==true)
        {
            return true;
        }
		return false;
	}
	for(int i=1;i<=N;i++)
	{
		if(isSafe(grid,row,col,i,N)){
			grid[row][col]=i;
			if(sudokuSolver(grid,N,target))
				return true;
			grid[row][col]=0;
		}
	}
	return false;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,testCase;
    cin>>t;
    for( testCase=1;testCase<=t;testCase++)
    {
        int n,val,target;
        cin>>n>>target;
        int **matrix = new int*[n+1];
        int **visited = new int*[n+1];
        for(int i=0;i<n+1;i++)
        {
            matrix[i]=new int[n+1];
            visited[i]= new int[n+1];
            for(int j=0;j<n+1;j++)
            {    
               matrix[i][j]=0;
               matriix[]
            } 
        }
            int failFlag =sudokuSolver(matrix,n,target);
            int sum=0;
            for(int i=1;i<=n;i++)
            {
                sum+=matrix[i][i];
            }
         
            if(!failFlag)
            {
                cout<<"Case #"<<testCase<<": "<<"IMPOSSIBLE"<<endl;
            }
            else 
            {
                cout<<"Case #"<<testCase<<": "<<"POSSIBLE"<<endl;
                for( int i=1;i<=n;i++)
                {
                    for(int j=1;j<=n;j++)
                    {
                        cout<<matrix[i][j]<<" ";
                    }
                    cout<<endl;
                } 
            }
            for(int i =0;i<=n;i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
    }
    return 0;
}