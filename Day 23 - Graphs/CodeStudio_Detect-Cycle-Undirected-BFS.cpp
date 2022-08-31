#include<bits/stdc++.h>

void convertor(unordered_map<int,list<int>>&adj,vector<vector<int>>& edges){
    for(int i = 0 ;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool cycledetectionusingBFS(unordered_map<int,list<int>>&adj,int source,vector<bool>&visited) {
    queue<pair<int,int>>q; // node and parent
    q.push({source,-1});
    visited[source] = true;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int node = x.first;
        int parent = x.second;
        for(auto it : adj[node]){
            if(visited[it] == false){
                visited[it] = true;
                q.push({it,x.first});
            }
            else if(visited[it] == true and it!=parent){
                return true;
            }
        }
    }
    return false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,list<int>> adj;
    convertor(adj,edges);
    vector<bool>visited(n+1,0);
    int V = n;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            if(cycledetectionusingBFS(adj,i,visited)){
                return "Yes";
            }
        }
    }
    return "No";
}
