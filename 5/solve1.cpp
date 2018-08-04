//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
//Example 1:
//
//Input: "babad"
//Output: "bab"
//Note: "aba" is also a valid answer.
//Example 2:
//
//Input: "cbbd"
//Output: "bb"

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        int maxn = 0;
        int index = 0;
        int len = s.length();
        int mode = -1;
        for (int i=0; i<len; i++) {
            int j = 0;
            while (i+j<len && i-j>=0 && s[i+j] == s[i-j]) 
                j++;
            if (maxn < 2*j-1) {
                maxn = 2*j-1;
                index = i;
                mode = 0;
            }
            j = 0;
            while (i+1+j<len && i-j>=0 && s[i+1+j] == s[i-j])
                j++;
            if (maxn < 2*j) {
                maxn = 2*j;
                index = i;
                mode = 1;
            }
        }
        if (mode == 0)
            return s.substr(index-(maxn-1>>1), maxn);
        else if (mode == 1)
            return s.substr(index+1-(maxn>>1), maxn);
    }
};
