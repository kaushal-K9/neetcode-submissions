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
public:
    //record the maximum imbalance uptil that node
    int imbalance = 0;

    int depth(TreeNode* root) {

        if (!root) return 0;

        int left = depth(root->left);
        if (left == -1) return -1;

        // int right = 1 + depth(root->right);
        //what if right subtree was already unbalanced and tried to return -1?
        int right = depth(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        //root will tell its parent its max depth so
        //parent can compare with other child
        return 1 + max(left, right);

    }
    bool isBalanced(TreeNode* root) {
       return depth(root) != -1;
    }
};