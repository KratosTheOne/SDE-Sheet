//T.C & S.C -> O(n * m) & O(n)

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {

        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();

        if(source.first == destination.first && source.second == destination.second)
            return 0;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && dis + 1 < dist[nr][nc])
                {
                    dist[nr][nc] = dis + 1;
                    if(nr == destination.first && nc == destination.second)
                        return 1 + dis;
                    q.push({1 + dis, {nr, nc}});
                }
            }
        }
        return -1;
    }
