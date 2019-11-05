//https://leetcode.com/problems/broken-calculator/

class Solution {
public:   
    int brokenCalc(int X, int Y) {
        int n=0;
        while (Y > X) {
            n++;
            if (Y%2 == 1) {
                Y++;
            } else{
                Y/=2;
            }
        }
        return n + X - Y;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int X = stringToInteger(line);
        getline(cin, line);
        int Y = stringToInteger(line);
        
        int ret = Solution().brokenCalc(X, Y);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
