//https://leetcode.com/problems/unique-paths/

class Solution {
public:
    
    int min(int a, int b){
        if (a<b) {return a;}
        else {return b;};
    }
    
    vector<vector<int>> generate(int numRows, int k) {
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
                    for (int i=2; i<numRows-1; i++) {
                        ans.push_back({1});
                        for (int j=1; j<min(i,k); j++)
                            ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
                        ans[i].push_back(1);
                    }
                    ans.push_back({1});
                        for (int j=1; j<k; j++)
                            ans[ans.size()-1].push_back(ans[ans.size()-2][j-1]+ans[ans.size()-2][j]);
                    return ans;
                }
            }
        }
    };
    
    int C (int n, int k){
        vector<vector<int>> ans = generate(n,k);
        return ans[n-1][k-1];
    }
    

    
    int uniquePaths(int m, int n) {
        return C(m+n-1, min(m,n));
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
