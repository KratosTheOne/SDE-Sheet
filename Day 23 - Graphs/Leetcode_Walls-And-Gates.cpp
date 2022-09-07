//T.C & S.C -> O(V+E) & O(V)

#include<bits/stdc++.h>

vector<vector<int>> wallsAndGates(vector<vector<int>> &grid, int n, int m) {

    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 0)
            {
                q.push({i, j});
            }
        }
    }

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr < 0 || nr == n || nc < 0 || nc == m || grid[nr][nc] == )
            {
                continue;
            }

            grid[nr][nc] = grid[r][c] + 1;
            q.push({nr, nc});
        }
    }
}
