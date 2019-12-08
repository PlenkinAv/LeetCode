//https://leetcode.com/problems/rotting-oranges/

class Solution {
public:        
    int count_ones(vector<vector<int>> grid){
        int ans = 0;
        for (int i = 0; i<grid.size(); i++)
            for (int j = 0; j<grid[i].size(); j++)
                if (grid[i][j] == 1) ans++;
        return ans;
    }
    
    void rot(vector<vector<int>> &grid, int &time){
        vector<vector<int>> new_grid = grid;
        for (int i = 0; i<grid.size(); i++)
            for (int j = 0; j<grid[i].size(); j++)
                if(grid[i][j] == 2){
                    if(i-1>=0 && grid[i-1][j]==1) new_grid[i-1][j] = 2;
                    if(j-1>=0 && grid[i][j-1]==1) new_grid[i][j-1] = 2;
                    if(i+1<grid.size() && grid[i+1][j]==1) new_grid[i+1][j] = 2;
                    if(j+1<grid[i].size() && grid[i][j+1]==1) new_grid[i][j+1] = 2;
                }
        time++;
        grid = new_grid;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int ones_old = 1000; 
        int ones_new = count_ones(grid);
        while(ones_old - ones_new > 0){
            rot(grid,time);
            ones_old = ones_new;
            ones_new = count_ones(grid);
        }
        if (ones_old - ones_new == 0 && ones_old != 0) return -1;
        else
            return time-1;        
    }
};