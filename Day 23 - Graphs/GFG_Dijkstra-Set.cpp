class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);

        st.insert({0, S});
        dist[S] = 0;

        while(!st.empty())
        {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);

            for(auto it : adj[node])
            {
                int edgeW = it[1];
                int adjNode = it[0];

                if(dis + edgeW < dist[adjNode])
                {
                    if(dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});

                    dist[adjNode] = dis + edgeW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};
