//T.C & S.C -> O(n log k) & O(n)
#include<bits/stdc++.h>
#define pp pair<int, int>

vector<int> KMostFrequent(int n, int k, vector<int> &nums)
{
    unordered_map<int, int> mp;

        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        priority_queue<pp, vector<pp>, greater<pp>> minHeap;

        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            minHeap.push({it -> second, it -> first});

            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        vector<int> ans;

        while(!minHeap.empty())
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
}
