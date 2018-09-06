//Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
//Example 1:
//
//Input: [2,3,-2,4]
//Output: 6
//Explanation: [2,3] has the largest product 6.
//Example 2:
//
//Input: [-2,0,-1]
//Output: 0
//Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int maxn = nums[0];
        for (int i=0; i<nums.size(); i++) {
            int cur_product = nums[i];
            maxn = max(maxn, cur_product);
            for (int j=i+1; j<nums.size(); j++) {
                cur_product *= nums[j];
                maxn = max(maxn, cur_product);
            }
        }
        return maxn;
    }
};
