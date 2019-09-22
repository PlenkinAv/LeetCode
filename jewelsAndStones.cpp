/* You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A". */

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int counter=0;
        for (int i=0; i<size(S); i++)
        {
            for (int j=0; j<size(J); j++)
            {
                if (S[i]==J[j]) {counter++;};
            }
        }
        return counter;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string J = stringToString(line);
        getline(cin, line);
        string S = stringToString(line);
        
        int ret = Solution().numJewelsInStones(J, S);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}