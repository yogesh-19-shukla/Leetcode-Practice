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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]] = i;
        }
        return f(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
    }

   TreeNode* f(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie,unordered_map<int,int>&inmap)
   {
       if(ps>pe || is>ie) return NULL;
       TreeNode* root = new TreeNode(preorder[ps]);

       int inroot = inmap[root->val];
       int numsleft = inroot - is;

        root->left = f(preorder,ps+1,ps+numsleft,inorder,is,inroot-1,inmap);
        root->right = f(preorder,ps+numsleft+1,pe,inorder,inroot+1,ie,inmap);
       return root;  
   }
};