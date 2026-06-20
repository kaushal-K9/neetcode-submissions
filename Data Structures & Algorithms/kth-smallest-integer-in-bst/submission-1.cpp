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
    int ans;
    int count = 0;

    void inorder (TreeNode* root, int k) {

        if (!root) return;

        inorder(root->left, k);

        //inorder from left returns after locating itself at the 
        //smallest value in BST

        //we start counting the ascending order of nodes
        count++;

        if (count == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);


    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};