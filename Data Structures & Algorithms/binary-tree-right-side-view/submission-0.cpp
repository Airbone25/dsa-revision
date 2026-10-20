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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }

        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        int curr = 0;

        while(!q.empty()){
            int n = q.size();
            v.push_back({});
            for(int i=0;i<n;i++){
                auto node = q.front();
                q.pop();
                v[curr].push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            curr++;
        }

        vector<int> res;

        for(auto i:v){
            res.push_back(i[i.size()-1]);
        }

        return res; 
    }
};
