class Solution
{
    //T.C & S.C -> O(nlogn) & O(n)

    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meetings;

        for(int i = 0; i < n; i++)
        {
            meetings.push_back(make_pair(end[i], start[i]));
        }

        sort(meetings.begin(), meetings.end());

        int lastEnd = meetings[0].first;
        int ans = 1;

        for(int i = 1; i < n; i++)
        {
            if(lastEnd < meetings[i].second)
            {
                ans++;
                lastEnd = meetings[i].first;
            }
        }

        return ans;
    }
};
