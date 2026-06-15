/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int count = 0;
    int dfs ( TreeNode* root, int max) {
        int res = 0;
        if ( !root ) {
            return 0;
        }
        if( root->val >= max ) {
            res = 1;
            max = root->val;
            count++;
        }
        res += dfs( root->left, max);
        res += dfs(root->right, max);
        return res;
    }
public:
    int goodNodes(TreeNode* root) {
        
        return dfs( root, root->val );
    }
};