//Given an encoded string, return it's decoded string.
//
//The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
//
//You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
//
//Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
//
//Examples:
//
//s = "3[a]2[bc]", return "aaabcbc".
//s = "3[a2[c]]", return "accaccacc".
//s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
class Solution {
public:
    string decodeString(string s) {
        stack<string> chars;
        stack<int> nums;
        string ans = "";
        int num = 0;
        for (int i=0; i<s.length(); i++) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            else if (isalpha(ch)) {
                ans.push_back(ch);
            }
            else if (ch == '[') {
                chars.push(ans);
                nums.push(num);
                ans = "";
                num = 0;
            }
            else if (ch == ']') {
                string str = ans;
                for (int j=0; j<nums.top()-1; j++) {
                    ans += str;
                }
                ans = chars.top() + ans;
                chars.pop();
                nums.pop();
            }
        }
        return ans;
    }
};
