/*The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance. */

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        while ((x>0) or (y>0))
        {
            if (((x%2==1) and (y%2==0)) or ((x%2==0) and (y%2==1)))
            {ans++;}
            x/=2;
            y/=2;
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
        int x = stringToInteger(line);
        getline(cin, line);
        int y = stringToInteger(line);
        
        int ret = Solution().hammingDistance(x, y);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}