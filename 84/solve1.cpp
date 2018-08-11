//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//Example:
//
//Input: [2,1,5,6,2,3]
//Output: 10

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxarea = 0;
        heights.push_back(0);
        for (int i=0; i<heights.size(); i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int index = s.top();
                s.pop();
                int area = heights[index] * (s.empty() ? i : i - s.top() - 1);
                maxarea = max(maxarea, area);
            }
            s.push(i);
        }
        heights.pop_back();
        return maxarea;
    }
};
