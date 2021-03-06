//Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return [-1, -1].
//
//Example 1:
//
//Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]
//Example 2:
//
//Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftmost = lower_bound(nums, target);
        int rightmost = lower_bound(nums, target+1)-1;
        if (leftmost < nums.size() && nums[leftmost] == target)
            return {leftmost, rightmost};
        return {-1, -1};
    }
    int lower_bound(const vector<int>& nums, const int target) {
        int n = nums.size();
        int high = n -1;
        int low = 0;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] < target)
                low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

