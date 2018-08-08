//Given a non-empty array of integers, return the k most frequent elements.
//
//For example,
//Given [1,1,1,2,2,3] and k = 2, return [1,2].
//
//Note: 
//You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> table;
        for(auto num: nums) {
            table[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto& ele : table) {
            minHeap.emplace(ele.second, ele.first);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        while (k--) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};

