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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        f(root,root->val,ans);
        return ans;
    }

    void f(TreeNode* root,int msf, int &ans){
        if(!root)  return;
        if(root->val>=msf){
            ans++;
        }
        f(root->left,max(msf,root->val),ans);
        f(root->right,max(msf,root->val),ans);
    }
};