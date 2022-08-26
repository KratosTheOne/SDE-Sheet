#include<bits/stdc++.h>

vector<int> build_lps(string s)
{
    int n = s.size();
    vector<int> lps(n);
    lps[0] = 0;

    int i = 1, len = 0;

    while(i < n)
    {
        if(s[len] == s[i])
        {
            lps[i] = len + 1;
            i++;
            len++;
        }
        else
        {
            if(len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else len = lps[len - 1];
        }
    }

    return lps;
}

int minCharsforPalindrome(string pat) {

    int n = pat.size();
    vector<int> lps = build_lps(pat);
    string txt = pat;
    reverse(txt.begin(), txt.end());

    int i = 0, len = 0;

    while(i < n)
    {
        if(pat[len] == txt[i])
        {
            i++;
            len++;
        }
        if(len == n)
            return 0;
        else if(i < n && pat[len] != txt[i])
        {
            if(len == 0) i++;
            else len = lps[len - 1];
        }
    }

    return n - len;
}

