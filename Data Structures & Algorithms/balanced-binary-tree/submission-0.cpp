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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        stack<pair<TreeNode*,int>> s;
        s.push({root,1});
        int h = 0;

        while(!s.empty()){
            auto [node,level] = s.top();
            s.pop();
            h = max(h,level);

            if(node->left){
                s.push({node->left,level+1});
            }
            if(node->right){
                s.push({node->right,level+1});
            }
        }

        return h;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            auto node = s.top();
            s.pop();

            int left = height(node->left);
            int right = height(node->right);

            int diff = abs(left-right);
            if(diff>1){
                return false;
            }

            if(node->left){
                s.push(node->left);
            }

            if(node->right){
                s.push(node->right);
            }
        }

        return true;
    }
};
