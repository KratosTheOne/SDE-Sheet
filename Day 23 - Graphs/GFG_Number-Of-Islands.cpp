//T.C & S.C -> O(n^2 * Num of Neigbours) & O(n^2)

class Solution {
  private:
    void bfs(int r, int c, int n, int m, vector<vector<char>>& grid,
    vector<vector<int>>& vis)
    {
        vis[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int delRow = -1; delRow <= 1; delRow++)
            {
                for(int delCol = -1; delCol <= 1; delCol++)
                {
                    int nrow = row + delRow;
                    int ncol = col + delCol;

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                    && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                if(!vis[r][c] && grid[r][c] == '1')
                {
                    cnt++;
                    bfs(r, c, n, m, grid, vis);
                }
            }
        }

        return cnt;
    }
};
