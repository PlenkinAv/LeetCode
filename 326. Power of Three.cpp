/* 
https://leetcode.com/problems/power-of-three/
Given an integer, write a function to determine if it is a power of three. */

class Solution {
public:
    bool isPowerOfThree(int n) {
        long int i=1;
        bool ans=false;
        while ( i<n )
        {
            i*=3;
            if (i==n) {ans=true;}
        };
        if (n==1) {ans=true;};
        return ans;
    } 
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        bool ret = Solution().isPowerOfThree(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
