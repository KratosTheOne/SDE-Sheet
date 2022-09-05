#include<bits/stdc++.h>
//using Topologival sort DFS - also known as Cycle Detection Method
//T.C & S.C -> O(v+e) & O(v) + O(v) for(auxi stack)

void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st)
{
    vis[node] = 1;

    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            dfs(it, adj, vis, st);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    int n = edges.size();

    vector<int> adj[v+1];

    for(int i = 0; i < n; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    stack<int> st;
    vector<int> vis(v,0);

    for(int i = 0; i < v; i++)
    {
        if(!vis[i])
            dfs(i, adj, vis, st);
    }

    vector<int> topo;

    while(!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}

/*
using Topologival sort BFS - also known as Kahn's Algorithm
T.C & S.C -> O(v+e) & O(v)

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    int n = edges.size();

    vector<int> adj[v+1];
    vector<int> indegree(v, 0);

    for(int i = 0; i < n; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    for(int i = 0; i < v; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node])
        {
            indegree[it]--;

            if(indegree[it] == 0)
                q.push(it);
        }
    }

    return topo;
}
*/
