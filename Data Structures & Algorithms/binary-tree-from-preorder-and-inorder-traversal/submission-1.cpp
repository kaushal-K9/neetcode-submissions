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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int&idx) {

        if (start > end) {
            return nullptr;
        }

        //get current root based on idx in preorder
        int rootVal = preorder[idx] ;
        int i = start;

        //get the position of root in inorder
        for (;i <= end; i++) {
            if (rootVal == inorder[i]) {
                break;
            }
        }

        //increment so that next root is known for next solve calls
        idx++;

        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(preorder, inorder, start, i - 1, idx);
        root->right = solve(preorder, inorder, i + 1, end, idx);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();

        int idx = 0;

        return solve(preorder, inorder, 0, n - 1, idx);
    }
};