//Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
//
//You need to find the shortest such subarray and output its length.
//
//Example 1:
//Input: [2, 6, 4, 8, 10, 9, 15]
//Output: 5
//Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
//Note:
//Then length of the input array is in range [1, 10,000].
//The input array may contain duplicates, so ascending order here means <=.

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minval =  INT_MAX;
        int maxval = INT_MIN;
        for (int i=1; i<n; i++) {
            if (nums[i] < nums[i-1]) {
                minval = min(minval, nums[i]);
            }
        }
        for (int i=n-2; i>=0; i--) {
            if (nums[i] > nums[i+1]) {
                maxval = max(maxval, nums[i]);
            }
        }
        int left, right;
        for (left=0; left<n; left++) {
            if (minval < nums[left]) {
                break;
            }
        }
        for (right=n-1; right>=0; right--) {
            if (maxval > nums[right]) {
                break;
            }
        }
        return right - left <= 0 ? 0 : right - left + 1;
    }
};

