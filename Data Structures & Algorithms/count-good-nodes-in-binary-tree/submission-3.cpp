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
    vector<int> ans;
    void dfs(TreeNode* root, int maxval)
    {
        if(root == nullptr)
            return;

        if(maxval <= root->val)
        {
            ans.push_back(root->val);
            maxval = root->val;
        }
        dfs(root->right, maxval);
        dfs(root->left, maxval);

        return;
    }

    int goodNodes(TreeNode* root) {
        dfs(root, -111);
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << "\n";
        return ans.size();   
    }
};
