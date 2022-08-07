#include <bits/stdc++.h>

//T.C & S.C -> O(32 * n * log(m)) & O(1)

int countNumbersLessThanMid(vector<int> row, int mid)
{
    int l = 0, h = row.size() - 1;

    while(l <= h)
    {
        int md = (l + h) >> 1;

        if(row[md] <= mid)
            l = md + 1;
        else
            h = md - 1;
    }

    return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    int low = 0, high = 1e5;
    int n = matrix.size(), m = matrix[0].size();

    while(low <= high)
    {
        int mid = (low + high) >> 1;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            count += countNumbersLessThanMid(matrix[i], mid);
        }

        if(count <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}
