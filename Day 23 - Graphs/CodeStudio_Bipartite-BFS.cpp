#include<bits/stdc++.h>

void convertor(unordered_map<int,list<int>>&adj,vector<vector<int>>& edges){
    for(int i = 0 ;i<edges.size();i++){
        for(int j = 0 ;j<edges[0].size();j++)
       {     if(edges[i][j] == 1)
              {
               adj[i].push_back(j);
               }
        }
//         adj[v].push_back(u);
    }
}

bool check(int start, int V, unordered_map<int,list<int>>&adj, vector<int>& color)
    {
        queue<int> q;
        q.push(start);

        color[start] = 1;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it : adj[node])
            {
                if(color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node])
                {
                    return false;
                }
            }
        }

        return true;
    }

bool isGraphBirpatite(vector<vector<int>> &edges) {

        int V = edges[0].size();
        unordered_map<int,list<int>> adj;
        convertor(adj,edges);
        vector<int> color(V, -1);

        for(int i = 0; i < V; i++)
        {
            if(color[i] == -1)
            {
                if(check(i, V, adj, color) == false)
                    return false;
            }
        }

        return true;
}
