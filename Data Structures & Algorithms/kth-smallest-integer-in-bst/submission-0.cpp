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
    vector<int> inorder(TreeNode* root){
        vector<int> ans;
        if(!root) return {};
        vector<int> left = inorder(root->left);
        vector<int> right = inorder(root->right);
        ans.insert(ans.end(),left.begin(),left.end());
        ans.push_back(root->val);
        ans.insert(ans.end(),right.begin(),right.end());

        return ans;
    }

    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> ino = inorder(root);
        return ino[k-1];
    }
};
