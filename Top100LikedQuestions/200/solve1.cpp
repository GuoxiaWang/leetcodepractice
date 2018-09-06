//Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
//Example 1:
//
//Input:
//11110
//11010
//11000
//00000
//
//Output: 1
//Example 2:
//
//Input:
//11000
//11000
//00100
//00011
//
//Output: 3


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        _grid = grid;
        int cnt = 0;
        _height = _grid.size();
        _width = _grid[0].size();
        for (int i=0; i<_height; i++) {
            for (int j=0; j<_width; j++) {
                if (_grid[i][j] == '1') {
                    cnt++;
                    BFS(i, j);
                }
            }
        }
        return cnt;
    }
    void BFS(int row, int col) {
        int dirx[] = {1,  0, -1, 0};
        int diry[] = {0, -1,  0, 1};
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        _grid[row][col] = '2';
        while (!q.empty()) {
            pair<int, int> pos = q.front();
            q.pop();
            
            for (int i=0; i<4; i++) {
                int r = pos.first + dirx[i];
                int c = pos.second + diry[i];
                if (r>=0 && r<_height && r >=0 && c < _width && _grid[r][c] == '1') {
                    q.push(make_pair(r, c));
                    _grid[r][c] = '2';
                }
            }
        }
    }
private:
    vector<vector<char>> _grid;
    int _height, _width;
};
