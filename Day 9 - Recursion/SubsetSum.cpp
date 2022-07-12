/*
Time Complexity: O(2^n)*k. Each index has two ways.
You can either pick it up or not pick it.
So for n index time complexity for O(2^n).

Space Complexity: O(2^n) for storing subset sums,
since 2^n subsets can be generated for an array of size n.
*/

class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        vector<int> ds;

        subset(0, arr, N, ans, ds);

        return ans;
    }

    void subset(int index, vector<int> &arr, int n, vector<int> &ans, vector<int> &ds)
    {
        if(index == n)
        {
            ans.push_back(sum(ds));
            return;
        }

        ds.push_back(arr[index]);
        subset(index + 1, arr, n, ans, ds);

        ds.pop_back();
        subset(index + 1, arr, n, ans, ds);
    }

    int sum(vector<int> &ds)
    {
        int value = 0;
        for(int i = 0; i < ds.size(); i++)
        {
            value += ds[i];
        }
        return value;
    }
};
