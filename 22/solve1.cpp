//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//For example, given n = 3, a solution set is:
//
//[
//  "((()))",
//  "(()())",
//  "(())()",
//  "()(())",
//  "()()()"
//]
//
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        generateParenthesisHelper("", n, 0);
        return ans;
    }
    void generateParenthesisHelper(string str, int leftNeed, int leftMore) {
        if (leftNeed == 0 && leftMore == 0) {
            ans.push_back(str);
            return;
        }
        if (leftNeed > 0) {
            generateParenthesisHelper(str + "(", leftNeed - 1, leftMore + 1);
        }
        if (leftMore > 0) {
            generateParenthesisHelper(str + ")", leftNeed, leftMore - 1);
        }
    }
private:
    vector<string> ans;
};
