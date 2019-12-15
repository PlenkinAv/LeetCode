//https://leetcode.com/problems/delete-nodes-and-return-forest/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* node, vector<TreeNode*>& result, set<int>& to_delete_set, bool is_root) {
        
        if (node == NULL) 
            return NULL;
        
        bool deleted = to_delete_set.find(node->val) != to_delete_set.end();
        if (is_root && !deleted) 
            result.push_back(node);
        
        node->left = solve(node->left, result, to_delete_set, deleted);
        node->right =  solve(node->right, result, to_delete_set, deleted);
        
        if (deleted) return NULL; else return node;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        vector<TreeNode*> result;
        set<int> to_delete_set;
        
        for (auto i : to_delete)
            to_delete_set.insert(i);
        
        solve(root, result, to_delete_set, true);
        
        return result;
    }
};