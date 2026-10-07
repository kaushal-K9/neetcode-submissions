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

    // root 

    // NLR   , LNR , LRN

    // root1, root2
    // base condition  root1,2 == null
    // N - present print r1 r2 , matchting return false
    // L - recru fun(r1->l,r2->l ) , 
    // R - recru fun(r1->r, r2->r)
    //  return true   

    bool checknode(TreeNode* n1, TreeNode* n2) {
        // base case
            // dono null - equql return ture
            if(n1 == nullptr && n2 == nullptr ) return true;
            // koi b ek null - return false
            if(n1 == nullptr || n2 == nullptr) return false;

            // eqaulity cvheck
            if( n1->val != n2->val) return false;

            // left
            bool leftCheck = checknode(n1->left,n2->left);
            // right
            bool rightCheck = checknode(n1->right, n2->right);

            return leftCheck && rightCheck;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {

        return checknode(p, q);
    }
};