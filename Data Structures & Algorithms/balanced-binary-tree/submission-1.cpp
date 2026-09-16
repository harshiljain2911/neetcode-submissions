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
    int height(TreeNode* root){
        
        if(!root) return 0;

        return 1 + max(height(root->right),height(root->left));

    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int leftheight = height(root->left);
        int rightheight = height(root->right);

        if(abs(leftheight-rightheight)>1) return false;
        
        return isBalanced(root->right) && isBalanced(root->left);
    }
};
