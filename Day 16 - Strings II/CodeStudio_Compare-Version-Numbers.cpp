#include<bits/stdc++.h>

int compareVersions(string version1, string version2)
{
        int i = 0, j = 0;
        int n = version1.size(), m = version2.size();

        while(i < n || j < m)
        {
            long long num1 = 0;
            long long num2 = 0;

            while(i < n && version1[i] != '.')
            {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            while(j < m && version2[j] != '.')
            {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            if(num1 > num2) return 1;

            if(num1 < num2) return -1;

            i++;
            j++;
        }

        return 0;
}
