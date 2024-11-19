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
    int rob(TreeNode* root) {
        pair<int,int>p = f(root);
        return max(p.first,p.second);
    }

    pair<int,int> f(TreeNode* root)
    {
        if(!root)  return {0,0};
        pair<int,int>left = f(root->left);
        pair<int,int>right = f(root->right);
        pair<int,int>res = {0,0};
        res.first = root->val + left.second + right.second;
        res.second = max(left.first,left.second) + max(right.first,right.second);
        return res;
    }
};