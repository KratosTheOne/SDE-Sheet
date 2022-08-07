#include<bits/stdc++.h>

int maximumActivities(vector<int> &start, vector<int> &finish) {

    int n = start.size();
    vector<pair<int, int>> vi;

    for(int i = 0; i < n; i++)
    {
        vi.push_back(make_pair(finish[i], start[i]));
    }

    sort(vi.begin(), vi.end());

    int lastEnd = vi[0].first;
    int maxActs = 1;

    for(int i = 1; i < n; i++)
    {
        if(lastEnd <= vi[i].second)
        {
            lastEnd = vi[i].first;
            maxActs++;
        }
    }

    return maxActs;
}
