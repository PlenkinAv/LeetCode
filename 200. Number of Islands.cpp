//https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void deleteConnected (vector<vector<char>> &grid, int i, int j){
        if (!(((i<0) or (j<0)) or ((i>grid.size()-1) or (j>grid[i].size()-1)))) {
            if (grid[i][j] == '1') {
                grid[i][j]='0';
                deleteConnected(grid, i+1, j);
                deleteConnected(grid, i, j+1);
                deleteConnected(grid, i-1, j);
                deleteConnected(grid, i, j-1);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for (int i=0; i<grid.size(); i++)
             for (int j=0; j<grid[i].size(); j++)
                if (grid[i][j] == '1') {
                    ans++;
                    deleteConnected(grid, i, j);
                }
        return ans;
    }
};