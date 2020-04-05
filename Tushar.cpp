#include<bits/stdc++.h>
using namespace std;

void printMatrix(int** mat, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int checkTrace(int** mat, int n, int k)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=mat[i][i];
    }
    if(sum==k)
        return true;
    return false;
}


bool isColSafe(int** mat, int col, int num,int n)
{
    for(int i=0;i<n;i++)
    {
        if(mat[i][col]==num)
        {
            return false;
        }
    }
    return true;
}


bool isRowSafe(int** mat, int row, int num,int n)
{
    for(int i=0;i<n;i++)
    {
        if(mat[row][i]==num)
        {
            return false;
        }
    }
    return true;
}


bool canPlace(int** mat, int row, int col, int num, int n)
{
    if(!isRowSafe(mat,row,num,n))
        return false;
    if(!isColSafe(mat,col,num,n))
        return false;
    return true;
}


bool sudokuSolver(int** mat, int n, int k)
{

    //printMatrix(mat,n);

    int row = -1;
    int col = -1;
    bool isEmpty = false;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {

            if(mat[i][j]==0)
            {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }

        }
        if(isEmpty)
        {
            break;
        }
    }

    if(!isEmpty)
    {
        return checkTrace(mat,n,k);
    }

    for(int num=1;num<=n;num++)
    {
        if(canPlace(mat,row,col,num,n))
        {
            mat[row][col] = num;
            if(sudokuSolver(mat,n,k))
            {
                return true;
            }
            mat[row][col] = 0;
        }
    }
    return false;
}


int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,k;
        cin>>n>>k;
        int** mat = new int*[n];

        for(int i=0;i<n;i++)
        {
            mat[i] = new int[n]();
            for(int j=0;j<n;j++)
            {
                mat[i][j] = 0;
            }
        }

        bool solutionExists = sudokuSolver(mat,n,k);

        if(solutionExists)
        {
            cout<<"Case #"<<i<<": POSSIBLE"<<endl;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<mat[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        else
        {
            cout<<"Case #"<<i<<": IMPOSSIBLE"<<endl;
        }
        for(int i=0;i<n;i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }
    return 0;
}
