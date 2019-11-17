//https://leetcode.com/problems/course-schedule/

class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, bool &cycle) {
        
        if (visited[node] == 1) {cycle = true; return;}
        
        visited[node] = 1;
        for (int i = 0; i < adj[node].size(); i++) {
            dfs(adj[node][i], adj, visited, cycle);
            if (cycle) return;
        }
        visited[node] = 2;
    }
    
    
    bool canFinish(int num, vector<vector<int>>& pre) {
       if(num==0) return true;
        
        vector<vector<int>> adj(num);
        for(int i=0; i<pre.size(); i++)
            adj[pre[i][1]].push_back(pre[i][0]);

        vector<int> visited(num, 0);

        bool cycle = false;
        for (int i = 0; i < num; i++) {
            if (cycle) return false;
            if (visited[i] == 0) dfs(i, adj, visited, cycle);
        }
        return !cycle;
    }
};