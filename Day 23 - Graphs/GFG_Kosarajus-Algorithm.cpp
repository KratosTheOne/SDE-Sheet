//T.C & S.C -> O(3 * (V + E)) & O(V + E)

class Solution
{
    private:
    void topoSort(int node, vector<int>& vis, vector<int> adj[], stack<int>& st)
    {
        vis[node] = 1;

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                topoSort(it, vis, adj, st);
            }
        }
        st.push(node);
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(V, 0);

        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                topoSort(i, vis, adj, st);
            }
        }

        vector<int> transpose[V];

        for(int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for(auto it : adj[i])
            {
                transpose[it].push_back(i);
            }
        }

        int count = 0;

        while(!st.empty())
        {
            int node = st.top();
            st.pop();

            if(!vis[node])
            {
                count++;
                topoSort(node, vis, transpose, st);
            }
        }

        return count;
    }
};
