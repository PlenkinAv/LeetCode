/*The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.

Given N, calculate F(N). */

class Solution {
public:
    int fib(int N) {
        int a=0 ,b=1, c=1;
        if (N==0) {return 0;} else {
        for (int i=0; i<N-1; i++)
        {   
            c=b;
            b=a+b;
            a=c;
        };
        return b;
        }
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);
        
        int ret = Solution().fib(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}