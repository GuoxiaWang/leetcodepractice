//Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
//
//Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//
//Example:
//
//matrix = [
//   [ 1,  5,  9],
//   [10, 11, 13],
//   [12, 13, 15]
//],
//k = 8,
//
//return 13.
//Note: 
//You may assume k is always valid, 1 ≤ k ≤ n2.

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); 
        int m = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[n-1][m-1] + 1;
        while (low < high) {
            int mid = low + ((high - low) >> 2);
            int j = m - 1;
            int cnt = 0; // count of less than mid;
            for (int i=0; i<n; i++) {
                while (j >=0 && matrix[i][j] > mid) j--;
                cnt += (j+1);
            }
            if (cnt < k) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};
