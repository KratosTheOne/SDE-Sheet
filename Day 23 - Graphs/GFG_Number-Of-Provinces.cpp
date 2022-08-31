//T.C & S.C -> O(n) + O(n) & O(n) + O(v + 2 * e)

class Solution {

  private:
    void dfs(int node, vector<int> adjList[], int vis[])
    {
        vis[node] = 1;

        for(auto it : adjList[node])
        {
            if(!vis[it])
            {
                dfs(it, adjList, vis);
            }
        }
    }

  public:
    int numProvinces(vector<vector<int>> adj, int V) {

        vector<int> adjList[V];

        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if(adj[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int vis[V] = {0};
        int counter = 0;

        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                counter++;
                dfs(i, adjList, vis);
            }
        }

        return counter;
    }
};
