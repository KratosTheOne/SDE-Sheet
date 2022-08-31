//T.C && S.C -> O(n * m * 4) & O(n * m)

class Solution
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();

	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    vector<vector<int>> dist(n, vector<int>(m, 0));

	    queue<pair<pair<int, int>, int>> q;

	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < m; j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                vis[i][j] = 1;
	                q.push({{i, j}, 0});
	            }
	            else
	                vis[i][j] = 0;
	        }
	    }

	    vector<int> dx = {-1, 0, 1, 0};
	    vector<int> dy = {0, 1, 0, -1};

	    while(!q.empty())
	    {
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int steps = q.front().second;

	        q.pop();

	        dist[r][c] = steps;

	        for(int i = 0; i < 4; i++)
	        {
	            int nr = r + dx[i];
	            int nc = c + dy[i];

	            if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0)
	            {
	                vis[nr][nc] = 1;
	                q.push({{nr, nc}, steps + 1});
	            }
	        }
	    }

	    return dist;
	}
};
