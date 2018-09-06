//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
//Example:
//
//Input:
//[
//  ["1","0","1","0","0"],
//  ["1","0","1","1","1"],
//  ["1","1","1","1","1"],
//  ["1","0","0","1","0"]
//]
//Output: 6


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        vector<int> heights(n);
        int maxarea = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i == 0) {
                    heights[j] = matrix[i][j] == '1' ? 1 : 0;
                }
                else {
                    if (matrix[i][j] == '0') {
                        heights[j] = 0;
                    }
                    else if (matrix[i-1][j] == '1' && matrix[i][j] == '1') {
                        heights[j]++;
                    }
                    else if (matrix[i-1][j] == '0' && matrix[i][j] == '1') {
                        heights[j] = 1;
                    }
                }
  
            }
            maxarea = max(maxarea, maximalHistogramArea(heights));
        }
        return maxarea;
    }
    int maximalHistogramArea(vector<int>& heights) {
        stack<int> s;
        int maxarea = 0;
        heights.push_back(0);
        for (int i=0; i<heights.size(); i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int tp = s.top();
                s.pop();
                int area = heights[tp] * (s.empty() ? i : i - s.top() - 1);
                maxarea = max(maxarea, area);
            }
            s.push(i);
        }
        heights.pop_back();
        return maxarea;
    }
};
