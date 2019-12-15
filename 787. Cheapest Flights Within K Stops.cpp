//https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int dst, int K) {
        
        vector<int> cost(n, INT_MAX/2);
        cost[src] = 0;
        
        for(int i=0; i<=K; i++){
            vector<int> C(cost);
            for(auto edge: a)
                C[edge[1]] = min(C[edge[1]], cost[edge[0]] + edge[2]);
            cost = C;
        }
        
        return cost[dst] == INT_MAX/2 ? -1 : cost[dst];
    }
};