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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)  return false;
        if(subRoot==NULL || same(root,subRoot))  return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }

    bool same(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL)  return true;
        if(p==NULL || q==NULL || p->val!=q->val)  return false;
        return same(p->left,q->left) && same(p->right,q->right);
    }
};