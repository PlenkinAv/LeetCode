/* Given an integer n, return the number of trailing zeroes in n!. */

class Solution {
public:
    int trailingZeroes(int n) {
        if (n<=4){return 0;}
        else
        {
            int counter5=0, smert=0;
            for (long int i=5; i<=n; i+=5) 
            {
                counter5++;
                smert=i;
                while ((smert>1) and (((smert/5)%5) == 0))
                {
                    counter5++;
                    smert/=5;
                };
            };
            return counter5; 
        };     
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().trailingZeroes(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}