#include <bits/stdc++.h>

double multiply(double num, int n)
{
    double ans = 1.0;
    for(int i = 1; i <= n; i++)
    {
        ans = ans * num;
    }

    return ans;
}

double findNthRootOfM(int n, int m) {

    double lo = 1;
    double hi = m;
    double eps = 1e-8;

    while((hi - lo) > eps)
    {
        double mid = (hi + lo) / 2.0;

        if(multiply(mid, n) < m)
        {
            lo = mid;
        }
        else
            hi = mid;
    }

    return lo;
}
