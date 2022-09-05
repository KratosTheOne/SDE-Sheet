//T.C & S.C -> O(V+E) & O(3*V)

class Solution {
  private:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int>& check)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it, adj, vis, pathVis, check) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVis[it])
            {
                check[node] = 0;
                return true;
            }
        }

        pathVis[node] = 0;
        check[node] = 1;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {

        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);
        vector<int> safeNodes;

        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
                dfs(i, adj, vis, pathVis, check);
        }

        for(int i = 0; i < V; i++)
        {
            if(check[i] == 1)
                safeNodes.push_back(i);
        }

        return safeNodes;

    }
};
