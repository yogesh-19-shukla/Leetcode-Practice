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
        if(root == NULL) return 0;
        f(root,d);
        return d;
    }

    int f(TreeNode* root, int &d){
        if(root==NULL)  return 0;
        int lh = f(root->left,d);
        int rh = f(root->right,d);
        d = max(d,lh+rh);
        return 1 + max(lh,rh);
    }
};