// T.C & S.C -> O(n) & O(n)

int Solution::solve(vector<int> &A, int B) {

    unordered_map<int, int> freq;
    int cnt = 0;
    int xorr = 0;

    for(auto it : A)
    {
        xorr ^= it;

        if(xorr == B)
            cnt++;

        if(freq.find(xorr ^ B) != freq.end())
        {
            cnt += freq[xorr ^ B];
        }
        freq[xorr] += 1;
    }
    return cnt;
}
