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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            auto node = s.top();
            s.pop();
            if(node){
                auto leftNode = node->left;
                node->left = node->right;
                node->right = leftNode;
                s.push(node->right);
                s.push(node->left);
            }
        }
        return root;
    }
};
