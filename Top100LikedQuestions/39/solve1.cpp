//Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
//The same repeated number may be chosen from candidates unlimited number of times.
//
//Note:
//
//All numbers (including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//Example 1:
//
//Input: candidates = [2,3,6,7], target = 7,
//A solution set is:
//[
//  [7],
//  [2,2,3]
//]
//Example 2:
//
//Input: candidates = [2,3,5], target = 8,
//A solution set is:
//[
//  [2,2,2,2],
//  [2,3,3],
//  [3,5]
//]
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        helper(candidates, target, v, 0, 0);
        return ans;
    }
    void helper(vector<int>& candidates, int target, vector<int> v, int pos, int sum) {
        if (pos == candidates.size()) return;
        if (sum > target) return;
        if (sum == target) {
            ans.push_back(v);
            return;
        }
        v.push_back(candidates[pos]);
        helper(candidates, target, v, pos, sum+candidates[pos]);
        v.pop_back();
        helper(candidates, target, v, pos + 1, sum);
    }
private:
    vector<vector<int>> ans;
};

