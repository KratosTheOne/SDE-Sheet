int longestSubSeg(vector<int> &nums , int n, int k){

    int i = 0, j = 0, czero = 0, maxi = 0;

    while(j < n)
    {
        if(nums[j] == 0)
            czero++;

        while(czero > k)
        {
            if(nums[i] == 0)
                czero--;

            i++;
        }

        maxi = max(maxi, j - i + 1);
        j++;
    }

    return maxi;
}

