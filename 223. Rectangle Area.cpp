//https://leetcode.com/problems/rectangle-area/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        int area1 = abs(C-A) * abs(D-B);
        int area2 = abs(G-E) * abs(H-F);
        
        int bot = max(F, B);
        int top = min(D, H);
        int left = max(A, E);
        int right = min(G, C);
        
        int intersec = 0;
        if(right > left && top > bot)
             intersec = (right - left) * (top - bot);
        
        return area1 + (area2 - intersec);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int A = stringToInteger(line);
        getline(cin, line);
        int B = stringToInteger(line);
        getline(cin, line);
        int C = stringToInteger(line);
        getline(cin, line);
        int D = stringToInteger(line);
        getline(cin, line);
        int E = stringToInteger(line);
        getline(cin, line);
        int F = stringToInteger(line);
        getline(cin, line);
        int G = stringToInteger(line);
        getline(cin, line);
        int H = stringToInteger(line);
        
        int ret = Solution().computeArea(A, B, C, D, E, F, G, H);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}