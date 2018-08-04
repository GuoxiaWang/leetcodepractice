class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int minval = INT_MAX;
        for (int i=0; i<n; i++) {
            if (prices[i] < minval) minval = prices[i];
            ans = max(ans, prices[i] - minval);
        }
        return ans;
    }
};
