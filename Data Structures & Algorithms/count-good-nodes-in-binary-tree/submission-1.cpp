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
    int goodNodes(TreeNode* root) {
        stack<pair<TreeNode*,int>> s;
        s.push({root,root->val});
        int count = 0;

        while(!s.empty()){
            auto [node,maxNode] = s.top();
            s.pop();
            if(node->val >= maxNode){
                count++;
                maxNode = node->val;
            }
            if(node->right){
                s.push({node->right,maxNode});
            }
            if(node->left){
                s.push({node->left,maxNode});
            }
        }

        return count;
    }
};
