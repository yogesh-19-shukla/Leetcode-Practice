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
        int ks = INT_MIN;
        f(root,cnt,ks,k);
        return ks;
    }

    void f(TreeNode* root, int &cnt, int &ks,int k){
        if(!root || cnt>k)  return;
        f(root->left,cnt,ks,k);
        cnt++;
        if(cnt==k){
            ks = root->val;
            return;
        }
        f(root->right,cnt,ks,k);
    }
};