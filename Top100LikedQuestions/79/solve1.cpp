//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
//Example:
//
//board =
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]
//
//Given word = "ABCCED", return true.
//Given word = "SEE", return true.
//Given word = "ABCB", return false.


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (search(board, i, j, word, 0, visited))
                    return true;
            }
        }
        return false;
    }
    bool search(vector<vector<char>>& board, int r, int c, string& word, int pos, vector<vector<bool>>& visited) {
        if (pos == word.length()-1 && board[r][c] == word[pos]) return true;
        if (board[r][c] != word[pos]) return false;
        visited[r][c] = true;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        int m = board.size();
        int n = board[0].size();
        for (int i=0; i<4; i++) {
            int r_new = r + dx[i];
            int c_new = c + dy[i];
            if (r_new >= 0 && r_new < m && c_new >= 0 && c_new < n
               && !visited[r_new][c_new]) {
                if (search(board, r_new, c_new, word, pos+1, visited))
                    return true;
            }
        }
        visited[r][c] = false;
        return false;
    }
};
