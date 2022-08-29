#include <bits/stdc++.h>
long getTrappedWater(long *nums, int n){

    int left = 0, right = n - 1;
    long long maxLeft = 0, maxRight = 0;
    long long maxWater = 0;

    while(left <= right)
    {
        if(nums[left] <= nums[right])
        {
            if(nums[left] >= maxLeft)
                maxLeft = nums[left];
            else
                maxWater += maxLeft - nums[left];
            left++;
        }
        else
        {
            if(nums[right] >= maxRight)
                maxRight = nums[right];
            else
                maxWater += maxRight - nums[right];
            right--;
        }
    }

    return maxWater;
}
