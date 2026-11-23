#include<bits/stdc++.h>
using namespace std;
#define V 5

int min_key(vector<int> &key,vector<bool>&mstset)
{
    int min = INT_MAX;
    int min_idx;

    for(int i=0; i<V; i++)
    {
        if(mstset[i]==false && key[i]<min)
        {
            min =key[i];
            min_idx = i;
        }
    }
    return min_idx;
}
void print(vector<int> &parent, vector<vector<int>> &Graph)
{
    int cost = 0;
  cout<<"Edge \tWeight\n";
  for(int i=0; i<V; i++)
  {
    cout<<parent[i]<<" - "<<i<<" \t"<<Graph[i][parent[i]]<<endl;
    cost += Graph[i][parent[i]];
    cout<<"Minimum Cost Spanning Tree: "<<cost<<endl;
  }
}
void prim_mst(vector<vector<int>>&Graph)
{

    vector<int>parent(V);
    vector<int>key(V);
    vector<bool>mstset(V);

    for(int i=0; i<V; i++)
    {
        key[i] = INT_MAX;
        mstset[i] = false;

    }
    key[0]=0;
    parent[0]=-1;

    for(int i=0; i<=V-2; i++)
    {
        int u = min_key(key,mstset);
        mstset[u] = true;
        for(int j=0; j<V; j++)
        {
            if(Graph[u][j] && mstset[j]==false && Graph[u][j]<key[j])
            {

                parent[j] = u;
                key[j] = Graph[u][j];
            }
        }

    }
    print(parent,Graph);




}

int main()
{


vector<vector<int>> Graph = {{ 0, 2, 0, 6, 0 },
{ 2, 0, 3, 8,5 },
{ 0, 3, 0, 0,7 },
{ 6, 8, 0, 0,9 },
{ 0, 5, 7, 9,0}};

prim_mst(Graph);
}
