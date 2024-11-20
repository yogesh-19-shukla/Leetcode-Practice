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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>tmp;
        f(root,targetSum,tmp,ans);
        return ans;
    }

    void f(TreeNode* root, int targetSum,vector<int>&tmp,vector<vector<int>> &ans)
    {
        if(!root)  return;
        tmp.push_back(root->val);
        if(!(root->left) && !(root->right) && root->val==targetSum){
            ans.push_back(tmp);
        }
        f(root->left,targetSum-root->val,tmp,ans);
        f(root->right,targetSum-root->val,tmp,ans);
        tmp.pop_back();
    }
};