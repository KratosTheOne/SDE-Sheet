/*
Time Complexity: O((2^n) *k*(n/2))

Reason: O(2^n) to generate every substring and O(n/2)
to check if the substring generated is a palindrome.
O(k) is for inserting the palindromes in another data structure,
where k  is the average length of the palindrome list.

Space Complexity: O(k * x)

Reason: The space complexity can vary depending upon the length of the answer.
k is the average length of the list of palindromes and
if we have x such list of palindromes in our final answer.
The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> path;
        partitionPal(0, s, path, res);
        return res;
    }

    void partitionPal(int index, string s, vector<string> &path,
              vector<vector<string> > &res) {
        if(index == s.size()) {
            res.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                partitionPal(i+1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
