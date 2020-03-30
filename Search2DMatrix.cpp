#include<bits/stdc++.h>
using namespace std;
bool colBinarySearch(vector<vector<int>> &matrix, int target ,int l , int u,int rowIndex)
{
    if(l==u)
    {
        if(matrix[rowIndex][l]==target)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    int mid=(l+u)/2;
    if(target < matrix[rowIndex][mid])
    {
        return colBinarySearch(matrix,target,l,mid,rowIndex);
    }
    else if(target > matrix[rowIndex][mid])
    {
        return colBinarySearch(matrix,target,mid+1,u,rowIndex);
    }
    else if(matrix[rowIndex][mid]==target)
    {
        return true;
    }
}
int rowBinarySearch(vector<vector<int>> &matrix, int target , int l, int u)
{

    if(l==u)
    {
        if(matrix[l][0]<=target)
        {
            return l;
        }
        else
        {
            return l-1;
        }
    }
    int mid=(l+u)/2;
    if(target < matrix[mid][0])
    {
        return rowBinarySearch(matrix,target,l,mid);
    }
    else if(target > matrix[mid][0])
    {
        return rowBinarySearch(matrix,target,mid+1,u);
    }
    else 
    {
        return mid;
    }
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    if(n==0)
    {
        return false;
    }
    if(matrix[0].size()==0)
    {
        return false;
    }
    int rowIndex=rowBinarySearch(matrix, target, 0,n-1);
    if(rowIndex==-1)
    {
        return false;
    }
    bool ans=colBinarySearch(matrix, target ,0, matrix[0].size()-1, rowIndex);
    return ans;
}

int main()
{
    int n,val,m,target;
    cin>>n>>m;
    vector<vector<int>> matrix(n);
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<m;j++)
        {
            cin>>val;
            matrix[i].push_back(val);
        }
    }
    cin>>target;
    cout<<"Final Ans :) "<<searchMatrix(matrix,target);

    return 0;
}