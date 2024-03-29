#include<bits/stdc++.h>

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
