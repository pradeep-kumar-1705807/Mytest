#include<bits/stdc++.h>
using namespace std;
class Graph
{
   public : int n;
            int edge;
            map<int, list<int>> adjList;

            Graph() 
            {

            }
            Graph(int n , int edge) 
            {
                this->n = n;
                this->edge = edge;
            }
            void addEdge(int u, int v, bool biDir=true) 
            {
                adjList[u].push_back(v);
                
                if(biDir == true)
                {
                    adjList[v].push_back(u);
                }
            } 

            void printGraph()
            {
                for(auto &row : adjList)
                {
                    int key= row.first;
                    cout<<"Key "<<key<<"-> ";
                    for(auto &nodes : row.second)
                    {
                        cout<<nodes<<",";
                    }
                    cout<<endl;
                }
               
            }
            int minRequired(vector<pair<int , int>> soldiers )
            {
                visited<bool> visited(n,false);
                for(auto &it : soldiers)
                {
                    if()
                }
            }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Graph g1;
        int n,r,k,u,v;
        cin>>n>>r>>k;
        vector<pair<int , int >> soliders(k);
        for(int i = 0;i < r; i++)
        {
            cin>>u>>v;
            g1.addEdge(u,v);
        }
        for(auto &it : soliders)
        {
            cin>>it.first>>it.second;
            it.first-=1;
        }
        g1.printGraph();

    }
}