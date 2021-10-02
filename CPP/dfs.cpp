#include<bits/stdc++.h>
using namespace std;


void dfsalgo(vector<int> adj[],int s,vector<int> &store,vector<int> &vis)
{
    store.push_back(s);
    vis[s]=1;

    for(auto it: adj[s])
    {
        if(vis[it]==-1)
        {
            dfsalgo(adj,it,store,vis);
        }
    }
}

vector<int> dfs(vector<int> adj[],int v)
{
    vector<int> store(v);
    vector<int> visited(v,-1);

    for(int i=0;i<v;i++)
    {
        if(visited[i]==-1)
        {
            dfsalgo(adj,i,store,visited);
        }
    }

    return store;
}

int main()
{
    int v;
    cin>>v;

    vector<int> adj[v];

    int e;
    cin>>e;

    for(int i=0;i<e;i++)
    {
        int s,d;
        cin>>s>>d;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }

    vector<int> vt=dfs(adj,v);

    for(int i=0;i<vt.size();i++)
    {
        cout<<vt[i]<<" ";
    }

    return 0;
}
