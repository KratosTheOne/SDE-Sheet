//T.C && S.C -> O(n + m) & O(m)

class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //lps creation
            vector<int> lps(pat.size(), 0);

            for(int i = 1; i < pat.size(); i++)
            {
                int j = lps[i - 1];

                while(j > 0 && pat[j] != pat[i])
                {
                    j = lps[j - 1];
                }

                if(pat[j] == pat[i]) j++;

                lps[i] = j;
            }

            //pattern searching way2
            int n = txt.size();
            int m = pat.size();
            int i = 0, j = 0;

            vector<int> ans;

            while(i < n)
            {
                if(pat[j] == txt[i])
                {
                    i++;
                    j++;
                }

                if(j == m)
                {
                    ans.push_back(i - (m - 1));
                    j = lps[j - 1];
                }

                else if(pat[j] != txt[i])
                {
                    if(j == 0) i++;

                    j = lps[j - 1];
                }
            }

            return ans;
        }

};
