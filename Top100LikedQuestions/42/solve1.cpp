//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//
//The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
//
//Example:
//
//Input: [0,1,0,2,1,0,1,3,2,1,2,1]
//Output: 6
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int ans = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] > left_max ? left_max = height[left] : ans += (left_max - height[left]);
                left++;
            }
            else {
                height[right] > right_max ? right_max = height[right] : ans += (right_max - height[right]);
                right--;
            }
        }
        return ans;
    }
};
