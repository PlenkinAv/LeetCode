//https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    
    unordered_map<Node*, Node*> table;
    
    Node* cloneGraph(Node* node) {    
        if(!node) return NULL;
        
        if (table.find(node) == table.end()){
            table[node] = new Node(node->val);
            
            for(auto n: node->neighbors)
                table[node]->neighbors.push_back(cloneGraph(n));
        }
        return table[node];
    }
};