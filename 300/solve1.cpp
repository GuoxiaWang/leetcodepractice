//Given an unsorted array of integers, find the length of longest increasing subsequence.
//
//Example:
//
//Input: [10,9,2,5,3,7,101,18]
//Output: 4 
//Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
//Note:
//
//There may be more than one LIS combination, it is only necessary for you to return the length.
//Your algorithm should run in O(n2) complexity.


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        int ans = 1;
        for (int i=1; i<n; i++) {
            int max_lis = 0;
            for (int j=0; j<i; j++) {
                if (nums[i] > nums[j]) {
                    max_lis = max(max_lis, dp[j]);
                }
            }
            dp[i] = max_lis + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
