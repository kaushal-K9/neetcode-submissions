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
// back-tracking, call by ref , call by val
   void good(TreeNode* root, int &gcc, int maxi) {
    if(root==NULL) return;
    if(root->val >= maxi) gcc++,maxi = root->val;
    good(root->left,gcc,maxi);
    good(root->right,gcc,maxi);
   }

    int goodNodes(TreeNode* root) {
        int gcc  =0;
        good(root,gcc,INT_MIN);
        return gcc;
    }
};