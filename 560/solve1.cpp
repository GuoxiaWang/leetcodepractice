//Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
//
//Example 1:
//Input:nums = [1,1,1], k = 2
//Output: 2
//Note:
//The length of the array is in range [1, 20,000].
//The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums = vector<int>(n+1, 0);
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += nums[i];
            sums[i+1] = sum;
        }
        int ans = 0;
        for (int i=0; i<n+1; i++) {
            for (int j=0; j<i; j++) {
                if (sums[i] - sums[j] == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
