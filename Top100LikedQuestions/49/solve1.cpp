//Given an array of strings, group anagrams together.

//Example:
//
//Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
//Output:
//[
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//]
//Note:
//
//All inputs will be in lowercase.
//The order of your output does not matter.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> indices;
        vector<vector<string>> ans;
        int cur_index = 0;
        for (int i=0; i<strs.size(); i++) {
            string str = strs[i];
            string key = str;
            sort(key.begin(), key.end());
            int index = -1;
            if (indices.find(key) != indices.end()) {
                index = indices[key];
                ans[index].push_back(str);
            }
            else {
                index = cur_index;
                indices[key] = index;
                vector<string> new_vec;
                new_vec.push_back(str);
                ans.push_back(new_vec);
                cur_index++;
            }
        }
        return ans;
    }
};
