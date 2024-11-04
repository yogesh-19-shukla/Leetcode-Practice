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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)  return {};
        vector<int> pre,post,in;
        stack<pair<TreeNode*,int>>st;
        st.push({root,1});
        while(!st.empty())
        {
           pair<TreeNode*,int> p = st.top(); st.pop();
           if(p.second==1){
            pre.push_back(p.first->val);
            p.second++;
            st.push(p);
            if(p.first->left!=NULL)    st.push({p.first->left,1});
           }
           else if(p.second==2){
            in.push_back(p.first->val);
            p.second++;
            st.push(p);
            if(p.first->right!=NULL)   st.push({p.first->right,1});
           }
           else{
            post.push_back(p.first->val);
           } 
        }
    return in;
    }
};