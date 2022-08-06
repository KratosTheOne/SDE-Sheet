#include<bits/stdc++.h>

bool mycmp(vector<int> & s1, vector<int> & s2){
    return s1[1] > s2[1];
}


int jobScheduling(vector<vector<int>> &jobs)
{
//     sort the jobs based on the time interval
    int total = 0;
    sort(jobs.begin(), jobs.end(), mycmp);
//     sort on basis of profit
//      find the maxium last date
    int maxi_deadline = jobs[0][0];
    for(int i = 1 ; i < jobs.size(); i++)
    {
        maxi_deadline = max(maxi_deadline , jobs[i][0]);
    }
    vector<int>arr(maxi_deadline + 1, -1);
    int countjobs = 0 , max_profit = 0;
    for(int i = 0 ;i < jobs.size(); i++)
    {
        for(int j = jobs[i][0]; j >= 1; j--)
        {
            if(arr[j] == -1)
            {
                arr[j] = jobs[i][0];
                countjobs++;
                max_profit += jobs[i][1];
                break;
            }
        }
    }

    return max_profit;
}
