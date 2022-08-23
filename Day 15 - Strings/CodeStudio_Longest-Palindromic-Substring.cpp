#include<bits/stdc++.h>

int expand(string s, int left, int right)
{
    while(left >= 0 && right < s.size() && s[left] == s[right])
    {
        left--;
        right++;
    }

    return right - left - 1;
}

string longestPalinSubstring(string str)
{
    if(str.length() < 1)
        return "";

    int start = 0, end = 0, maxLen = 0;

    for(int i = 0; i < str.length(); i++)
    {
        int odd = expand(str, i, i);
        int even = expand(str, i, i + 1);

        int len = max(odd, even);

        if(maxLen < len)
        {
            maxLen = len;
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return str.substr(start, maxLen);
}
