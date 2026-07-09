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

    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;

        vector<int> vals;
        inorder(vals, root);

        int low = vals[0];
        for(int i = 1; i < vals.size(); i++)
        {
            if(low >= vals[i])
                return false;

            low = vals[i];
        }
        return true;
        
    }
};
