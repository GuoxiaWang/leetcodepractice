//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
//Example 1:
//
//Input: "(()"
//Output: 2
//Explanation: The longest valid parentheses substring is "()"
//Example 2:
//
//Input: ")()())"
//Output: 4
//Explanation: The longest valid parentheses substring is "()()"

class Solution {
public:
    int longestValidParentheses(string s) {
        int leftcnt = 0, rightcnt = 0;
        int maxlen = 0;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(') leftcnt++;
            else rightcnt++;
            if (leftcnt == rightcnt) maxlen = max(maxlen, 2*rightcnt);
            if (rightcnt > leftcnt) leftcnt = rightcnt = 0;
        }
        leftcnt = rightcnt = 0;
        for (int i=s.length()-1; i>=0; i--) {
            if (s[i] == '(') leftcnt++;
            else rightcnt++;
            if (leftcnt == rightcnt) maxlen = max(maxlen, 2*leftcnt);
            if (leftcnt > rightcnt) leftcnt = rightcnt = 0;
        }
        return maxlen;
    }
};
