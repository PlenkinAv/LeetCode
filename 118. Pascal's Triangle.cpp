//https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {};
        if (numRows == 0) {return ans;}
        else{
            ans.push_back({1});
            if(numRows == 1) {
                return ans;
            }
            else{
                ans.push_back({1,1});
                if(numRows == 2) {
                    return ans;
                }
                else{
                    for (int i=2; i<numRows; i++) {
                        ans.push_back({1});
                        for (int j=1; j<i; j++)
                            ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
                        ans[i].push_back(1);
                    }
                    return ans;
                }
            }
        }
    };
};