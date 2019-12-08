// https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    
    void DFS(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int prev, int i, int j) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || prev > matrix[i][j] || visited[i][j])              return;
        visited[i][j] = true;
        DFS(matrix, visited, matrix[i][j], i + 1, j);
        DFS(matrix, visited, matrix[i][j], i - 1, j);
        DFS(matrix, visited, matrix[i][j], i, j - 1);
        DFS(matrix, visited, matrix[i][j], i, j + 1);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        if (m == 0) return vector<vector<int>>();
        int n = matrix[0].size();
        
        vector<vector<int>> res;
        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            DFS(matrix, p, INT_MIN, i, 0);
            DFS(matrix, a, INT_MIN, i, n - 1);
        }
        
        for (int j = 0; j < n; j++) {
            DFS(matrix, p, INT_MIN, 0, j);
            DFS(matrix, a, INT_MIN, m - 1, j);    
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i][j] && a[i][j]) 
                    res.push_back(vector<int> {i, j});
            }
        }
        return res; 
    }
};