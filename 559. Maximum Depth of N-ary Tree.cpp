//https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void A_R_B (Node* node, int n, int &k)
    {
        if ( k<n ) 
            k=n;

        if( node == NULL) 
            return;
        
        for (int i=0; i<node->children.size(); i++) 
            A_R_B(node->children[i], n+1, k);
    }
    
    int maxDepth(Node* root) {
        int k = 0;
        int n = 1;
        if (root) {
            A_R_B (root, n, k);
            return k;
        }
        else return 0;
    }
};