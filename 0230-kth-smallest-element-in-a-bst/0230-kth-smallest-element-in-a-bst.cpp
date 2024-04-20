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
        int cnt = 0;
        int ksmallest = INT_MIN;
        inorder(root,cnt,ksmallest,k);
        return ksmallest;
    }

    void inorder(TreeNode* root, int &cnt, int &ksmallest,int k)
    {
        if(root==NULL || cnt>=k)  return;
        inorder(root->left,cnt,ksmallest,k);
        cnt++;
        if(cnt==k)
        {
            ksmallest = root->val;
            return;
        }
        inorder(root->right,cnt,ksmallest,k);
    }
};