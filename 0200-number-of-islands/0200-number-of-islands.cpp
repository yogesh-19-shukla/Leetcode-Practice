class Solution {
private:
    void dfs( vector<vector<char>>& grid,int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] != '1'){
                return;
            }
            
       
       grid[i][j] = '2'; // mark as visited
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};