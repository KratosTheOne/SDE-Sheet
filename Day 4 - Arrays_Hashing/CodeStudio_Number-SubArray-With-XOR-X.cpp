#include <bits/stdc++.h>
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> freq;
    int cnt = 0;
    int xorr = 0;

    for(auto it : arr)
    {
        xorr ^= it;

        if(xorr == x)
            cnt++;

        if(freq.find(xorr ^ x) != freq.end())
            cnt += freq[xorr ^ x];

        freq[xorr] += 1;
    }

    return cnt;
}
