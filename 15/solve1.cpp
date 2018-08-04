//Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note:
//
//The solution set must not contain duplicate triplets.
//
//Example:
//
//Given array nums = [-1, 0, 1, 2, -1, -4],
//
//A solution set is:
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n == 0) return ans;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; i++) {
            int a = -nums[i];
            int j = i+1;
            int k = n-1;
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum < a) {
                    j++;
                }
                else if (sum > a) {
                    k--;
                }
                else {
                    int b = nums[j];
                    int c = nums[k];
                    ans.push_back({-a, b, c});
                    while (j < k && nums[j] == b) j++;
                    while (j < k && nums[k] == c) k--;
                }
            }
            while (i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};
