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
    void inorder(vector<int>& vals, TreeNode* root)
    {
        if(root == nullptr)
            return;

        inorder(vals, root->left);
        vals.push_back(root->val);
        inorder(vals, root->right);

        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> vals;
        inorder(vals, root);

        return vals[k-1];
    }
};
