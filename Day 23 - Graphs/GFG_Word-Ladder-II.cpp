/*T.C & S.C -> This will vary on examples to examples as there can be multiple
               sequences, So its kinda like next to impossible.
               but if we specifically look for this example it will be
               O(N * WordLen * 26) & O(N * M)
*/

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<vector<string>> q;
        q.push({beginWord});

        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);

        int level = 0;
        vector<vector<string>> ans;

        while(!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            //Erase all the words that has been used in previous levels;
            if(vec.size() > level)
            {
                level++;

                for(auto it : usedOnLevel)
                {
                    st.erase(it);
                }

                usedOnLevel.clear();
            }

            string word = vec.back();

            //Building the ans vector
            if(word == endWord)
            {
                //First list of ans
                if(ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                else if(ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
            }

            for(int i = 0; i < word.size(); i++)
            {
                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if(st.count(word) > 0)
                    {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }

                word[i] = original;
            }
        }

        return ans;
    }
};
