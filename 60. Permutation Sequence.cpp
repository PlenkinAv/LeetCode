//https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    int fact(int n)
    {
        int res=1;
        for (int i=1; i<=n; i++)
            res*=i;
        return res;
    }
    string getPermutation(int n, int k) {
        string ans;
        string pool="123456789";
        int a=n;
        int j=k;
        while (a>0)
        {
            int f=fact(a-1);
            int i=0;
            while (j>0)
            {
                j-=f;
                i++;
            }
            j+=f;
            ans += pool[i-1];
            for (int j=i-1; j<size(pool)-1; j++)
                swap(pool[j], pool[j+1]);
            a-=1;
        }
        return ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        string ret = Solution().getPermutation(n, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
