#include<bits/stdc++.h>

bool isPossible(vector<int> &positions , int n ,  int cows, int minDist)
{
    int countCows = 1;
    int cowsPlaced = positions[0];

    for(int i = 0; i < n; i++)
    {
        if(positions[i] - cowsPlaced >= minDist)
        {
            countCows++;
            cowsPlaced = positions[i];
        }
    }

    if(countCows >= cows)
        return true;

    return false;
}

int chessTournament(vector<int> positions , int n ,  int c){

    sort(positions.begin(), positions.end());

    int low = 1, high = positions[n - 1] - positions[0];

    while(low <= high)
    {
        int mid = (low + high) >> 1;
        if(isPossible(positions, n, c, mid))
            low = mid + 1;
        else
            high = mid - 1;
    }

    return high;
}
