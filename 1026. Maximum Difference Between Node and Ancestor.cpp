//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int difference(TreeNode* node, int reference)
{
    int dif = abs(reference - node->val);
    
    if(node->left != NULL) {
        dif = max(dif, difference(node->left, reference));
    }
    
    if(node->right != NULL) {
        dif = max(dif, difference(node->right, reference));
    }
    
    return dif;
}

void A_R_B (TreeNode* node, vector<int> &ans)
{   
    if( node == NULL) 
    {
        return;
    }
    else
    {
        ans.push_back( difference( node, node->val ) );
    }
    
    if(node->left != NULL) {
        A_R_B(node->left, ans);
    }
    
    if(node->right != NULL) {
        A_R_B(node->right, ans);
    }
}

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        vector <int> ans;
        int dif;
        A_R_B(root, ans);
        dif = ans[0];
        for (int i=0; i<ans.size(); i++)
        {
            if ( dif < ans[i] ) { dif = ans[i]; };
        }
        return dif;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().maxAncestorDiff(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}