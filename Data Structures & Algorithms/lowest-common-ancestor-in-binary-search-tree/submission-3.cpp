/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val == root->val || q->val == root->val) return root;
        
        //always keep p lesser than q when passing to functions
        if (p->val > q->val) swap(p,q);

        if (p->val <= root->val && q->val >= root->val) return root;

        if (p->val < root->val) return lca(root->left, p, q);
        else return lca(root->right, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {  
        return lca(root, p, q);
    }
};


// fun(r,p,q)
//     p ==r | q == r return  r
//     p < r && q>r return r

//     p < r -> return fun(rl,p,q);
//     else return f(rr,p,q);




