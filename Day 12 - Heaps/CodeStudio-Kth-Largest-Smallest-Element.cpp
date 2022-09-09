#include<bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &nums, int n, int k)
{
    priority_queue<int> maxh;
	priority_queue<int, vector<int>, greater<int>> minh;
    vector<int> ans(2);

    for(int i = 0; i < n; i++)
    {
        maxh.push(nums[i]);
        if(maxh.size() > k)
            maxh.pop();
    }
    ans[0] = maxh.top();

    for(int i = 0; i < n; i++)
    {
        minh.push(nums[i]);
        if(minh.size() > k)
            minh.pop();
    }
    ans[1] = minh.top();

    return ans;
}
