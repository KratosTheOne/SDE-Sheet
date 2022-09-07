#include<bits/stdc++.h>

//T.C & S.C -> O(3 * (V + E)) & O(V + E)

void topoSort(int node, vector<int>& vis, vector<int> adj[], stack<int>& st)
{
    vis[node] = 1;

    for(auto it : adj[node])
    {
        if(!vis[it])
            topoSort(it, vis, adj, st);
    }

    st.push(node);
}

void revDfs(int node, vector<int>& vis, vector<int> transpose[], vector<int>& res)
{
    vis[node] = 1;
    res.push_back(node);
    for(auto it : transpose[node])
    {
        if(!vis[it])
            revDfs(it, vis, transpose, res);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    vector<int> adj[n];
    vector<int> vis(n, 0);
    stack<int> st;

    for(auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }

    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            topoSort(i, vis, adj, st);
        }
    }

    vector<int> transpose[n];

    for(int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for(auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        if(!vis[node])
        {
            vector<int> res;
            revDfs(node, vis, transpose, res);
            ans.push_back(res);
        }
    }

    return ans;
}
