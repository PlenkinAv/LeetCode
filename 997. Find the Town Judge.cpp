//https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> in(N+1);
        vector<int> out(N+1);
        int res = -1;

        for(int i=0; i<trust.size(); i++)
        {
            out[trust[i][0]]++;
            in[trust[i][1]]++; 
        }

        for(int i=1; i<N+1; i++)
            if(in[i]==N-1 && out[i]==0)
                res = i;

        return res;
    } 
};