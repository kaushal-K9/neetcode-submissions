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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        
        //when root is the only node in that subtree for which the call is made
        if (start > end) return NULL;

        //the roots are obtained one by one from preorder
        int rootVal = preorder[idx];

        //find the target element index in inorder to split the elements in left and right
        int i = start;

        for(; i <=end; i++) {
            if (inorder[i] == rootVal) break;
        }

        //make a new node
        TreeNode* root = new TreeNode(rootVal);
        //advance the index before calling the left child
        idx++;

        root->left = solve(preorder, inorder, start, i - 1, idx);
        root->right = solve(preorder, inorder, i + 1, end, idx);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        int idx = 0; //used for preorder array

        return solve(preorder, inorder, 0, n - 1, idx);
    }
};