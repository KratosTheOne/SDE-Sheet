//T.C & S.C -> O(n * m * 4) & O(n * m)

class Solution {
  private:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>& list, int r0, int c0)
    {
        int n = grid.size(), m = grid[0].size();

        vis[r][c] = 1;
        list.push_back({r - r0, c - c0});

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1)
            {
                dfs(nr, nc, grid, vis, list, r0, c0);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> list;
                    dfs(i, j, grid, vis, list, i, j);
                    st.insert(list);
                }
            }
        }

        return st.size();
    }
};
