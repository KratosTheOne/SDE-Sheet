#include <bits/stdc++.h>
int uniqueSubstrings(string input)
{
    vector<int> mp(256, -1);
    int n = input.size();
    int l = 0, r = 0, len = 0;

    while(r < n)
    {
        if(mp[input[r]] != -1)
            l = max(l, mp[input[r]] + 1);

        mp[input[r]] = r;

        len = max(len, r - l + 1);

        r++;
    }
    return len;
}
