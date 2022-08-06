//T.C & S.C -> O(n * m) & O(1)

/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

bool comp(Job a, Job b)
{
    return a.profit > b.profit;
}

class Solution
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job a[], int n)
    {
        sort(a, a + n, comp);

        int maxi = a[0].dead;

        for(int i = 1; i < n; i++)
        {
            maxi = max(maxi, a[i].dead);
        }

        int slot[maxi + 1];
        for(int i = 0; i <= maxi; i++)
            slot[i] = -1;

        int countJobs = 0, maxProfit = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = a[i].dead; j > 0; j--)
            {
                if(slot[j] == -1)
                {
                    slot[j] = i;
                    countJobs++;
                    maxProfit += a[i].profit;
                    break;
                }
            }
        }

        return {countJobs, maxProfit};
    }
};
