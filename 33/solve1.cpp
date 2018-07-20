//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
//You are given a target value to search. If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//Example 1:
//
//Input: nums = [4,5,6,7,0,1,2], target = 0
//Output: 4
//Example 2:
//
//Input: nums = [4,5,6,7,0,1,2], target = 3
//Output: -1


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int high = n-1;
        int low = 0;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target)
                return mid;
            if ((target < nums[mid] && (nums[mid] < nums[high] || target >= nums[low]  && nums[mid] > nums[low]))
               || (target > nums[mid] && target > nums[high] && nums[mid] < nums[low]))
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return -1;
    }
};
