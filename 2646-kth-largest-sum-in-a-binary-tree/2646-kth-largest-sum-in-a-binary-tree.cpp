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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long,vector<long long>,greater<>>pq;
        bfs(root,k,0,pq);
        return (pq.size()<k) ? -1 : pq.top();
    }

    void bfs(TreeNode* root, int k,int level,auto&pq)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            long long sum = 0;
            for(int i=0;i<n;i++){
                auto node = q.front(); 
                q.pop();
                sum += node->val;
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            pq.push(sum);
            if (pq.size()>k) pq.pop();
        }
    }
};