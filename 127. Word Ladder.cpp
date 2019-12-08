//https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> set(wordList.begin(), wordList.end());
        int distance = 1;
        queue<string> bst;
        bst.push(beginWord);
        string word;
        
        while(! bst.empty()){
            int q_size = bst.size();
            for (int i=0; i<q_size; i++){
                word = bst.front(); 
                bst.pop(); 
                if (word == endWord) return distance;
                set.erase(word);
                for (int j=0; j<word.size(); j++){
                    char ch = word[j];
                    for (char k='a'; k <= 'z'; k++){
                        word[j] = k;
                        if (set.find(word) != set.end())
                            bst.push(word);
                    }
                word[j] = ch;    
                } 
            }
        distance++;
        }
        return 0;
    }
};