//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//Example:
//
//Input: "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//Note:
//
//Although the above answer is in lexicographical order, your answer could be in any order you want.

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        table = vector<string>(10);
        table[2] = "abc";
        table[3] = "def";
        table[4] = "ghi";
        table[5] = "jkl";
        table[6] = "mno";
        table[7] = "pqrs";
        table[8] = "tuv";
        table[9] = "wxyz";
        if (digits.length() > 0) {
            for (int i=0; i<table[digits[0]-'0'].length(); i++) {
                string str = string(1, table[digits[0]-'0'][i]);
                letterCombinationsCore(digits, 1, str);
            }
        }
        return permutation;
    }
    void letterCombinationsCore(string digits, int cur, string word) {
        if (cur == digits.length()) {
            permutation.push_back(word);
            return;
        }
        for (int i=0; i<table[digits[cur]-'0'].length(); i++) {
            string str = word;
            str.append(1, (table[digits[cur]-'0'][i]));
            letterCombinationsCore(digits, cur+1, str);
        }        
    }
    
private:
    vector<string> permutation;
    vector<string> table;
    
};
