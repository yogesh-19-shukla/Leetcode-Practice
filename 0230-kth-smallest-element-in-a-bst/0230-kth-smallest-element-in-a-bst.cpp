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
    int kthSmallest(TreeNode* root, int k) {
        int ks = INT_MAX;
        f(root,ks,k);
        return ks;
    }

    void f(TreeNode* root, int &ks ,int &k)
    {
        if(root==NULL)  return;
        f(root->left,ks,k);
        k--;
        if(k==0){
            ks = min(ks,root->val);
            return;
        }
        f(root->right,ks,k);
    }
};