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
    int maxLevelSum(TreeNode* root) {
        if(!root)  return 0;
        queue<TreeNode*> q;
        int level = 0;
        int minl = 0;
        int sum = INT_MIN;
        q.push(root);
        while(!q.empty()){
            int lsum = 0;
            int n = q.size();
            level++;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                lsum += node->val;
                if(node->left)   q.push(node->left);
                if(node->right)  q.push(node->right);
            }
            if(lsum>sum){
                sum = lsum;
                minl = level;
            }
        }
        return minl;
    }
};