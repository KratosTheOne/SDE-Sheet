//T.C & S.C -> O(n)
#include<bits/stdc++.h>

void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, vector<int> &ls)
{
    vis[node] = true;
    ls.push_back(node);

    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            dfs(it, adj, vis, ls);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //Prepare adjList
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> vis;

    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            vector<int> ls;
            dfs(i, adj, vis, ls);
            ans.push_back(ls);
        }
    }

    return ans;
}
