//T.C & S.C -> O(V+E) & O(V)

class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
	    queue<int> q;
	    vector<int> inDegrees(V, 0);

	    for(int i = 0; i < V; i++)
	    {
	        for(auto it : adj[i])
	        {
	            inDegrees[it]++;
	        }
	    }

	    for(int i = 0; i < V; i++)
	    {
	        if(inDegrees[i] == 0)
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
	            inDegrees[it]--;
	            if(inDegrees[it] == 0)
	                q.push(it);
	        }
	    }

	    return topo;
	}
};
