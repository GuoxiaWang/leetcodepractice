//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
//Example:
//
//Input: 
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//
//Output: 4


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int maxn = 0;
        for (int r=1; r<=n; r++) {
            for (int c=1; c<=m; c++) {
                if (matrix[r-1][c-1] == '1') {
                    dp[r][c] = min(min(dp[r-1][c], dp[r][c-1]), dp[r-1][c-1]) + 1;
                    maxn = max(maxn, dp[r][c]);
                }
            }
        }
        return maxn * maxn;
    }
};
