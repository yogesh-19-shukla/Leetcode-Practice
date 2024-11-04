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
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        dia(root,d);
        return d;
    }
    int dia(TreeNode* root, int& d){
        if(root==NULL)  return 0;
        int l = dia(root->left,d);
        int r = dia(root->right,d);
        d = max(d,l+r);
        return 1 + max(l,r);
    }

};