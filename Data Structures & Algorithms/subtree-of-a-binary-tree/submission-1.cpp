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
    bool isSame(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;

        if (a->val != b->val) return false;

        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //if subroot is NULL it can be any nodes child in root
        if (!subRoot) return true;

        if (!root) return false;

        //check if root has the startig point of a subtree
        if (isSame(root, subRoot)) return true;

        //check if subtree exists in the left or right of root, by saying
        //if i call the isSubtree function on left and right child with subroot
        //at one node, it will eventually be a question of sameTree as subroot
        //and that call is made via isSubtree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};