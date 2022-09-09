#define pp pair<int , pair<int , int>>

vector<int> Solution::solve(vector<vector<int> > &grid) {

    int m=grid.size();
    int n=grid[0].size();

    priority_queue<pp, vector<pp>, greater<pp>> pq;

    for(int i = 0;i < m; i++)
    {
        pq.push({grid[i][0], {i, 0}});
    }

    vector<int> ans;

    while(!pq.empty())
    {
        int x = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();

        ans.push_back(x);

        if(j != n-1)
        {
            pq.push({grid[i][j+1], {i, j+1}});
        }
    }
    return ans;
}

