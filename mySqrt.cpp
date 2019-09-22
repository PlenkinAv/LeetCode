/* Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned. */

class Solution {
public:
    int mySqrt(int x) 
    {
        if (x==0) {return 0;} else {
            
        double est=1, prev=0, eps=0.1;
        while( ((prev-est)*(prev-est)) > eps )
        {
            prev=est;
            est=(est+(x/est))/2;
        }
        return (int)est;}
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}