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
    int helper(TreeNode* root, int maxsofar) {
        if (!root) return 0;
        if (root->val >= maxsofar)
            return 1 + helper(root->left, max(root->val, maxsofar)) +
                   helper(root->right, max(root->val, maxsofar));
        return helper(root->left, max(root->val, maxsofar)) +
               helper(root->right, max(root->val, maxsofar));
    }

    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        return helper(root, root->val);
    }
};
