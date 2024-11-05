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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        vector<vector<int>>res;
        if(!root)  return res;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* tmp = p.first;
            int v = p.second.first;
            int l = p.second.second;
            mp[v][l].insert(tmp->val);
            if(tmp->left){
                q.push({tmp->left,{v-1,l+1}});
            }
            if(tmp->right){
                q.push({tmp->right,{v+1,l+1}});
            }
        }
        for(auto i : mp){
            vector<int>col;
            for(auto j : i.second){
                col.insert(col.end(),j.second.begin(),j.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};