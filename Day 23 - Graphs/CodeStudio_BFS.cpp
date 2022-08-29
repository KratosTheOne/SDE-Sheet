//T.C & S.C -> O(v + e)

#include<bits/stdc++.h>

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &vis, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = 1;

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto it : adjList[frontNode])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> vis;
    vector<int> ans;

    prepareAdjList(adjList, edges);

    for(int i = 0; i < vertex; i++)
    {
        if(!vis[i])
        {
            bfs(adjList, vis, ans, i);
        }
    }

    return ans;
}
