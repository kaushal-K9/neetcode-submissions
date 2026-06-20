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
    //record a max on the dfs pathway
    int dfsCount(TreeNode* root, int max) {

        if (!root) return 0;

        //can the current node add to the count? if yes
        //we make it 1 and add ahead
        int found = 0;

        if (root->val >= max) {
            //set found to 1
            found = 1;
            //update max value in the dfs path
            max = root->val;
        }

        found += dfsCount(root->left, max) + dfsCount(root->right, max);

        return found;
    }
    int goodNodes(TreeNode* root) {
        return dfsCount(root, root->val);
    }
};