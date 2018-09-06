//Given a string, your task is to count how many palindromic substrings in this string.
//
//The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
//
//Example 1:
//Input: "abc"
//Output: 3
//Explanation: Three palindromic strings: "a", "b", "c".
//Example 2:
//Input: "aaa"
//Output: 6
//Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
//Note:
//The input string length won't exceed 1000.

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i=0; i<2*s.length()-1; i++) {
            int left = i / 2;
            int right = i / 2 + i % 2;
            while (left >=0 && right < s.length() && s[left] == s[right]) {
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
};
