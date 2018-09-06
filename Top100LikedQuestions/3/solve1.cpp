//Given a string, find the length of the longest substring without repeating characters.
//
//Examples:
//
//Given "abcabcbb", the answer is "abc", which the length is 3.
//
//Given "bbbbb", the answer is "b", with the length of 1.
//
//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index(128, -1);
        int i=0, j=0;
        int n = s.length();
        int maxn = 0;
        while (j < n) {
            i = max(index[s[j]], i);
            maxn = max(maxn, j+1-i);
            index[s[j]] = j+1;
            j++;
        }
        return maxn;
    }
};

