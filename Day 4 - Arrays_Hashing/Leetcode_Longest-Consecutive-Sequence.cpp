//T.C & S.C -> 3*O(n) & O(1)

class Solution {
public:

    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> hashSet;
        for(int num : nums)
            hashSet.insert(num);

        int longestStreak = 0;

        for(int num : nums)
        {
            if(!hashSet.count(num - 1))
            {
                int currentNum = num;
                int currentStreak = 1;

                while(hashSet.count(currentNum + 1))
                {
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};

/*
T.C & S.C -> O(nlogn) & O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0){
            return 0;
        }

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 1;
        int prev = nums[0];
        int curr = 1;

        for(int i = 1; i < n; i++)
        {
            if(nums[i] == prev+1)
                curr++;
            else if(nums[i] != prev)
                curr = 1;

            prev = nums[i];
            ans = max(ans, curr);
        }
        return ans;
    }
};
*/
