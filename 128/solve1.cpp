//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//Your algorithm should run in O(n) complexity.
//
//Example:
//
//Input: [100, 4, 200, 1, 3, 2]
//Output: 4
//Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            int num = nums[i];
            if (m[num]) continue;
            m[num] = num;                  
            if (m.find(num-1) != m.end())
                m[num] = findParent(num-1);
            if (m.find(num+1) != m.end())
                m[num+1] = m[num];
        }
        for (int i=0; i<nums.size(); i++) {
            ans = max(ans, nums[i] - findParent(nums[i]) + 1);
        }
        return ans;
    }
    int findParent(int n) {
        while(m[n] != n) {
            n = m[n] = m[m[n]];
        }
        return n;
    }
private:
    unordered_map<int, int> m;
};

