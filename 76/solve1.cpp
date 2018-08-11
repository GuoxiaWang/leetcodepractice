//
//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
//Example:
//
//Input: S = "ADOBECODEBANC", T = "ABC"
//Output: "BANC"
//Note:
//
//If there is no such window in S that covers all characters in T, return the empty string "".
//If there is such window, you are guaranteed that there will always be only one unique minimum window in S.


class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(256, 0);
        for (int i=0; i<t.length(); i++) {
            map[t[i]]++;
        }
        int count = t.size(); 
        int begin=0, end=0;
        int len = INT_MAX;
        int pos = 0;
        while (end < s.length()) {
            if (map[s[end]] > 0) { 
                count--;
            }
            map[s[end]]--;
            end++;
            while (map[s[begin]] < 0) {
                map[s[begin]]++;
                if (map[s[begin]] > 0)
                    count++;
                begin++;
            }
            if (count == 0 && end - begin < len) {
                len = end - begin;
                pos = begin;
            }
        }
        return len == INT_MAX ? "" : s.substr(pos, len);
    }
};

