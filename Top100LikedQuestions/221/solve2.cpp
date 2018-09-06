class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m+1, 0);
        int maxn = 0;
        int last_c_1 = 0;
        for (int r=1; r<=n; r++) {
            for (int c=1; c<=m; c++) {
                int tmp = dp[c];
                if (matrix[r-1][c-1] == '1') {
                    dp[c] = min(min(dp[c], dp[c-1]), last_c_1) + 1;
                    maxn = max(maxn, dp[c]);
                }
                else {
                    dp[c] = 0;
                }
                last_c_1 = tmp;
            }
            
        }
        return maxn * maxn;
    }
};
