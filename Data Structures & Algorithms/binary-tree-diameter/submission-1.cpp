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
    int depth(TreeNode* root) {
        if (!root) return 0;

        int left = 1 + depth(root->left);
        int right = 1 + depth(root->right);

        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                
                diameter = max(diameter, depth(temp->left) + depth(temp->right));
            }
        }

        return diameter;
    }
};