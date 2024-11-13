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
    bool isValidBST(TreeNode* root) {
        return f(root,NULL,NULL);
    }

    bool f(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){
        if(!root)  return true;
        if(minNode && root->val<=minNode->val || maxNode && root->val>=maxNode->val)  return false;
        return f(root->left,minNode,root) && f(root->right,root,maxNode);

    }
};