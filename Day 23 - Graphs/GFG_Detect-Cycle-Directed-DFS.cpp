//T.C & S.C -> O(v + e) & O(v)

class Solution {
  private:
    bool dfs(int node, vector<int> adj[], vector<int>& vis)
    {
        vis[node] = 2;

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it, adj, vis) == true)
                    return true;
            }
            else if(vis[it] == 2)
                return true;
        }

        vis[node] = 1;

        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {

        vector<int> vis(V, 0);

        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, adj, vis) == true)
                    return true;
            }
        }

        return false;
    }
};
