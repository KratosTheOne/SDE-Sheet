#include<bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> nse(n, -1);
    stack<int> s;

    for(int i = n - 1; i >= 0; i--)
    {
        while(!s.empty() && s.top() >= arr[i])
            s.pop();

        if(i < n)
            if(!s.empty())
                nse[i] = s.top();

        s.push(arr[i]);
    }

    return nse;
}
