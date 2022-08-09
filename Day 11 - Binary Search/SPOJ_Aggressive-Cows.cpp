//T.C & S.C -> O(n * logn) & O(1)

#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPossible(ll n, ll cows, vector<ll> stalls, ll minDist)
{
    int countCows = 1;
    ll cowPlaced = stalls[0];

    for(int i = 1; i < n; i++)
    {
        if(stalls[i] - cowPlaced >= minDist)
        {
            countCows++;
            cowPlaced = stalls[i];
        }
    }

    if(countCows >= cows)
        return true;

    return false;
}

void solve()
{
    ll n, c;
    cin >> n >> c;
    vector<ll> stalls;
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        stalls.push_back(x);
    }

    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls[n - 1] - stalls[0];

    while(low <= high)
    {
        ll mid = (low + high) >> 1;

        if(isPossible(n, c, stalls, mid))
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << high << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
