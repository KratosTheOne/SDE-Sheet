#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int left = 0, right = m - 1, top = 0, bottom = n - 1;

    while(left < right && top < bottom)
    {
        for(int i = top; i < bottom; i++)
            swap(mat[i][left], mat[i + 1][left]);

        for(int i = left; i < right; i++)
            swap(mat[bottom][i], mat[bottom][i + 1]);

        for(int i = bottom; i > top; i--)
            swap(mat[i][right], mat[i - 1][right]);

        for(int i = right; i > left + 1; i--)
            swap(mat[top][i], mat[top][i - 1]);

        top++;
        left++;
        bottom--;
        right--;
    }
}
