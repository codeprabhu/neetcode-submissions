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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        int n = (p == nullptr)? 1: 0;
        int m = (q == nullptr)? 1: 0;
        if(n == 1 && m == 1)
            return true;
        else if(n == 0 && m == 0)
        {
            if(p->val != q->val)
                return false;
        
            bool left = isSameTree(p->left, q->left);
            bool right = isSameTree(p->right, q->right);
            return (left&&right);
        }
        else 
            return false;

        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        int n = (root == nullptr)? 1: 0;
        int m = (subRoot == nullptr)? 1:0;
        if(m)
            return true;
        else if(n)
            return false;
        else{
            if(isSameTree(root, subRoot))
            return true;
        
            if(isSubtree(root->left, subRoot))
                return true;
            if(isSubtree(root->right, subRoot))
                return true;

            return false;
        }
    }   
};
