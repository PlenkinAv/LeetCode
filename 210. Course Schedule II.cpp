//https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    void add_edge(int u, int v, vector<vector<int>> &graph) {
        graph[u].push_back(v);
    }
    
    vector<int> findOrder(int num, vector<vector<int>>& prer) {
        
        vector<vector<int>>graph(num);
        vector<int> mark(num, 0);
        queue<int> q;
        vector<int> result;
        
        for (auto edge: prer) {
            int u = edge[1], v = edge[0];
            add_edge(u, v, graph);
            mark[v]++;
        }
        for (int i = 0; i < mark.size(); i++) {
            if (mark[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            result.push_back(u);
            for (auto v: graph[u]) {
                mark[v]--;
                if (mark[v] == 0) q.push(v);
            }
        }
        if(result.size() == num) return result; else return vector<int>();
    }
};