//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.
//
//Example:
//
//Input:
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//Output: 7
//Explanation: Because the path 1→3→1→1→1 minimizes the sum.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        vector<int> dp(n+1);
        for (int i=0; i<m; i++) {
            for (int j=1; j<=n; j++) {
                if (i == 0){
                    dp[j] = dp[j-1] + grid[i][j-1];
                }
                else if (j == 1) {
                    dp[j] = dp[j] + grid[i][j-1];
                }
                else {
                    dp[j] = min(dp[j] + grid[i][j-1], dp[j-1] + grid[i][j-1]);
                }
            }
        }
        return dp[n];
    }
};
