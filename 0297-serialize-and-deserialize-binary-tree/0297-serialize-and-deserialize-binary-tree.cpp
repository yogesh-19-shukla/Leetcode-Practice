/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)   return "NULL,";
        string ans = to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s;
        queue<string>q;
        for(int i=0;i<data.size();i++)
        {
            if(data[i]==','){
                q.push(s);
                s="";
                continue;
            }
            s+=data[i];
        }
        if(s.size()!=0)  q.push(s);
        return f(q);
    }

    TreeNode* f(queue<string>&q)
    {
        string s = q.front();  q.pop();
        if(s=="NULL")  return NULL;
        TreeNode* node = new TreeNode(stoi(s));
        node->left = f(q);
        node->right = f(q);
        return node;
    }




};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));