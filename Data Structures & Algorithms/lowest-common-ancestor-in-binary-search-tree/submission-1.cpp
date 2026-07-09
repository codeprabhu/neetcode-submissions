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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval = p->val, rootval = root->val, qval = q->val;
        if(pval > rootval && qval > rootval)
            return lowestCommonAncestor(root->right, p, q);
        if(pval < rootval && qval < rootval)
            return lowestCommonAncestor(root->left, p, q);
        
        return root;
    }
};
