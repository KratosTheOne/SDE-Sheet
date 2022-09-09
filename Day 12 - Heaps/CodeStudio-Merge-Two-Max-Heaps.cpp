#include<bits/stdc++.h>

//T.C & S.C -> O(n log n) & O(n + m)

void heapify(vector<int>&ans, int size, int i)
{
        int largest = i;
        int leftC = 2 * i + 1;
        int rightC = 2 * i + 2;

        if(leftC < size && ans[largest] < ans[leftC])
        {
            largest = leftC;
        }

        if(rightC < size && ans[largest] < ans[rightC])
        {
            largest = rightC;
        }

        if(largest != i)
        {
            swap(ans[largest], ans[i]);
            heapify(ans, size, largest);
        }
}

vector<int> mergeHeap(int n, int m, vector<int> &a, vector<int> &b) {
        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            ans.push_back(a[i]);
        }

        for(int i = 0; i < m; i++)
        {
            ans.push_back(b[i]);
        }

        int size = ans.size();

        for(int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(ans, size, i);
        }

        return ans;
}
