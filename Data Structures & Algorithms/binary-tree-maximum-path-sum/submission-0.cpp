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
    long long func(TreeNode* root, long long& maxSum) {

        //to do: base case
        if (!root) return 0;

        long long lmax = func(root->left, maxSum);
        long long rmax = func(root->right, maxSum);

        maxSum = max({maxSum, lmax + rmax + root->val, lmax + root->val, rmax + root->val, (long long)root->val});

        return max((long long)root->val, root->val + max(lmax, rmax));
    }
    int maxPathSum(TreeNode* root) {
        
        long long maxSum = LLONG_MIN;

        func(root, maxSum);

        return (int)maxSum;

    }
};