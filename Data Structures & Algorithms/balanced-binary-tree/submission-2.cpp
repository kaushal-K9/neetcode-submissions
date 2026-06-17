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
        
        int left = 1 + depth(root->left);
        int right = 1 + depth(root->right);

        //imbalance is carried over to the root
        imbalance = max(imbalance, abs(left - right));

        //root will tell its parent its max depth so
        //parent can compare with other child
        return max(left, right);

    }
    bool isBalanced(TreeNode* root) {
        depth(root);
        return imbalance < 2;
    }
};